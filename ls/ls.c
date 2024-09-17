#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

#include "argop.h"

#include "ls.h"
#include "manage_op.h"


int main(int argc, char *argv[]) {
    argOp_t *argOp = NULL;
    if((argOp = malloc((argc - 1) * sizeof(argOp_t))) == NULL)
        errorHandler(ERROR_MEMORY);

    initFlags(argc, argv, argOp);

    // The flags has priority because they interrupt the ls command
    if(has_flag) manageFlag(argc, argOp);

    free(argOp);

    return 0;
}


void initFlags(int argc, char *argv[], argOp_t argOp[]) {
    const char *setOp[] = {
        "--block-size=",
        "--color=",
        "--classify=",
        "--format=",
        "--hide=",
        "--hyperlink=",
        "--indicator-style=",
        "--ignore=",
        "--indicator-style=",
        "--quoting-style=",
        "--sort=",
        "--time=",
        "--time-style=",
        "--tabsize=",
        "--width=",
        NULL
    };

    const char *flag[] = {
        "--help",
        "--version",
        NULL
    };

    // The ix should respect the mult options
    const char *option[] = {
        "--all",
        "--almost-all",
        "--escape",
        "--ignore-backups",
        "",
        "",
        "--directory",
        "--dired",
        "",
        "",
        "",
        "--no-group",
        "--human-readable",
        "--dereference-command-line",
        "--inode",
        "",
        "--kibibytes",
        "",
        "--dereference",
        "",
        "--numeric-uid-gid",
        "--literal",
        "",
        "",
        "--hide-control-chars",
        "--quote-name",
        "--reverse",
        "--recursive",
        "--size",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "--context",
        "",

        "--author",
        "--file-type",
        "--full-time",
        "--group-directories-first",
        "--si",
        "--dereference-command-line-symlink-to-dir",
        "--show-control-chars",
        "--zero",
        NULL
    };

    checkFullArgs(
        argc,
        argv,
        argOp,
        1,
        1,
        OP_AMOUNT,
        setOp,
        flag,
        option
    );
}


void errorHandler(error_t error, ...) {
    va_list arg;
    va_start(arg, error);

    printf("ls: ");

    switch(error) {
        case ERROR_MEMORY:
            perror("problem allocating.\n");
            break;

        default:
            perror("unkown error.\n");
            break;
    }

    va_end(arg);

    exit(EXIT_FAILURE);
}