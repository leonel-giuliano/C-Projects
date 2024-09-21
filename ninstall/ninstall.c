#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

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
    else manageOption(argc, argv, argOp);

    if(bad_usage) errorHandler(ERROR_ARG);

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


void errorHandler(errorEvent_t error, ...) {
    va_list arg;
    va_start(arg, error);

    printf("ninstall: ");

    switch(error) {
        case ERROR_ARG:
            puts("bad usage of the program");
            puts("Check the '--help' flag for help");
            break;

        case ERROR_COMMENT:
            printf("couldn't find '%s'", va_arg(arg, const char *));
            break;

        case ERROR_FILE:
        case ERROR_DIR:
            printf("cannot access '%s': ", va_arg(arg, const char *));
            fflush(stdout);
            perror("");
            break;

        case ERROR_FCLOSE:
        case ERROR_CLOSEDIR:
            printf("problem closing '%s': ", va_arg(arg, const char *));
            fflush(stdout);
            perror("");
            break;

        case ERROR_NOMEM:
            fflush(stdout);
            perror("problem allocating");
            break;
    }

    va_end(arg);

    exit(EXIT_FAILURE);
}
