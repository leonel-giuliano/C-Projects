#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "ninstall.h"
#include "detect-args.h"


int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX) errorHandler(ERROR_ARG);

    // Set all the list of operations
    const char *command[] = {
        "new",
        "edit",
        "remove",
        "show",
        NULL
    };

    const char *option1[] = {
        "-h",
        "-l",
        NULL
    };

    const char *option2[] = {
        "--help",
        "--list",
        NULL
    };

    // Check the arguments operations
    argOperation_t argOp[AMOUNT_OPERATION];
    uint8_t detectError = detectArgs(argc, argv, argOp, AMOUNT_OPERATION, command, option1, option2);
    if(detectError) errorHandler(ERROR_MEMORY);

    return 0;
}

void errorHandler(error_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            puts("There was a bad usage when using ninstall.\n");
            break;

        case ERROR_MEMORY:
            perror("There was a problem when allocating memory.");
            break;

        default:
            perror("[DEBUG] strange outcome from the errorHandler.");
            break;
    }

    exit(EXIT_FAILURE);
}