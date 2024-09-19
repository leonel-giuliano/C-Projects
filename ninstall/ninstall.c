#include <stdio.h>
#include <stdlib.h>

#include "argop.h"

#include "ninstall.h"
#include "manage-op.h"


int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX) errorHandler(ERROR_ARG);

    argOp_t argOp[ARGC_MAX - 1];
    initFlags(argc, argv, argOp);

    // This happens if an operation was used more than once
    if(bad_usage) errorHandler(ERROR_ARG);

    // The flags have priority
    if(has_flag) manageFlag(argc, argOp);

    return 0;
}


void initFlags(int argc, char *argv[], argOp_t argOp[]) {
    const char *flag[] = {
        "--help",
        "--version",
        NULL
    };

    const char *option[] = {
        "new",
        "edit",
        "list",
        "remove",
        NULL
    };

    const char *flagRm0[] = {
        "-y",
        "-n",
        NULL
    };

    const char *flagRm1[] = {
        "--remove-file",
        "--keep-file",
        NULL
    };

    checkArgs(argc, argv, argOp, OP_AMOUNT, flag, option, flagRm0, flagRm1);
}


void errorHandler(error_t error) {
    printf("ninstall: ");

    switch(error) {
        case ERROR_ARG:
            puts("Bad usage of the ninstall program");
            puts("Check the '--help' flag for help");
            break;

        default:
            perror("[DEBUG] Unkown error");
            break;
    }

    exit(EXIT_FAILURE);
}