#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "argop.h"

#include "ls.h"


int main(int argc, char *argv[]) {
    argOp_t *argOp = NULL;
    if((argOp = malloc((argc - 1) * sizeof(argOp_t))) == NULL)
        errorHandler(ERROR_MEMORY);

    initFlags(argc, argv, argOp);

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
}


void errorHandler(error_t error) {
    switch(error) {
        case ERROR_MEMORY:
            perror("Problem allocating.\n");
            break;

        default:
            perror("Unkown error.\n");
            break;
    }

    exit(EXIT_FAILURE);
}