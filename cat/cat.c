#include <stdio.h>
#include <stdlib.h>

#include "argop.h"

#include "cat.h"


int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX) errorHandler(ERROR_ARG);

    // Check the operation of every argument
    // The "- 1" is to ignore the command
    argOp_t argOp[ARGC_MAX - 1];
    initFlags(argc, argv, argOp);

    return 0;
}


void initFlags(int argc, char *argv[], argOp_t argOp[]) {
    const char *flags[] = {
        "--help",
        "--version",
        NULL
    };

    const char *option1[] = {
        "--show-all",
        "--number-nonblank",
        "--show-ends",
        "--number",
        "--squeeze-blank",
        "--show-tabs",
        "--show-nonprinting",
        NULL
    };

    // The "- 1" is because of the mult options
    checkArgs(argc, argv, argOp, OP_AMOUNT - 1, flags, option1);
}


void errorHandler(error_t error) {
    switch(error) {
        case ERROR_ARG:
            puts("Bad usage of the cat function.");
            break;

        default:
            perror("Unkown error.");
            break;
    }

    exit(EXIT_FAILURE);
}