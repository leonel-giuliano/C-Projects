#include <stdio.h>
#include <stdlib.h>

#include "ninstall.h"
#include "detect-args.h"


int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX) errorHandler(ERROR_ARG);

    // Set the operations lists of the function
    const char *comm[] = {
        "new",
        "edit",
        NULL
    };

    const char *opt1[] = {
        "-h",
        "-l",
        NULL
    };

    const char *opt2[] = {
        "--help",
        "--list",
        NULL
    };

    // Get the operation of every argument
    argOperation_t argOp[AMOUNT_OPERATION];
    detectArgs(argc, argv, &argOp, AMOUNT_OPERATION, comm, opt1, opt2);

    return 0;
}

void errorHandler(error_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            puts("There was a bad usage of the ninstall command.\n");
            break;

        default:
            perror("[DEBUG] strange outcome of the errorHandler");
            break;
    }

    exit(EXIT_FAILURE);
}