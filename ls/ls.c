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

    const char *option[] = {
        "--all",
        "--almost-all",
        "--author",
        "--escape",
        "--ignore-backups",
        "--directory",
        "--dired",
        "--file-type",
        "--full-time",
        "--group-directories-first",
        "--no-group",
        "--human-readable",
        "--si",
        "--dereference-command-line",
        "--dereference-command-line-symlink-to-dir",
        "--inode",
        "--kibibytes",
        "--dereference",
        "--numeric-uid-gid",
        "--literal",
        "--hide-control-chars",
        "--show-control-chars",
        "--quote-name",
        "--reverse",
        "--recursive",
        "--size",
        "--context",
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

    // Even though is not used, it gets set if an operation appears more than once
    // and that doesn't mean a bad usage for the ls command
    bad_usage = 0;
}


void errorHandler(error_t error, ...) {
    va_list arg;
    va_start(arg, error);

    printf("ls: ");

    switch(error) {
        case ERROR_DIR:
            printf("cannot access '%s': No such file or directory.\n", va_arg(arg, const char *));
            break;

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