#include <stdio.h>
#include <stdlib.h>

#include "new-alias.h"
#include "detect-args.h"


int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX) errorHandler(ERROR_ARG);

    // Array that tells the type and operation for every argument
    argOperation_t argOperation[ARGC_MAX];
    initFlags(argc, argv, argOperation);

    return 0;
}

void initFlags(int argc, char *argv[], argOperation_t *argOp) {
    const char *comm[] = {
        "new",
        "edit",
        "remove",
        "list",
        NULL
    };

    const char *option1[] = {
        "-h",
        "-s",
        "-d",
        NULL
    };

    const char *option2[] = {
        "--help",
        "--static",
        "--dynamic",
        NULL
    };

    detectArgs(argc, argv, AMOUNT_OPERATION, argOp, comm, option1, option2);
}

void errorHandler(error_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            puts("There was a bad usage of the command.");
            break;

        default:
            perror("[DEBUG] Unkown error.");
            break;
    }

    exit(EXIT_FAILURE);
}