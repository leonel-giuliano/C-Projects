#include <stdio.h>
#include <stdlib.h>

#include "ninstall.h"
#include "detect-args.h"


int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX) errorHandler(ERROR_ARG);

    // Manage the arguments and flags from the script
    argOperation_t argOp[ARGC_MAX - 1] = { NO_OPERATION };
    initFlags(argc, argv, argOp);

    return 0;
}

void initFlags(int argc, char *argv[], argOperation_t argOp[]) {
    const char *comm[] = {
        "new",
        "edit",
        "list",
        NULL
    };

    const char *option1[] = {
        "-h",
        NULL
    };

    const char *option2[] = {
        "--help",
        NULL
    };

    const char *interrupt[] = {
        "-h",
        "--help",
        NULL
    };

    detectArgs(argc, argv, argOp, AMOUNT_OP, interrupt, comm, option1, option2);
}

op_t checkFlags(int argc, argOperation_t argOp[]) {
    op_t op = OP_PRED;
    // Pointer to the function depending on the operations
    void (*checkF)(int, argOperation_t[]) = NULL;

    if(has_interruption) op = OP_INTERRUPT;
    else if(has_comm) {
        // Search for a command
        for(uint8_t i = 0; i < argc - 1; i++) {
            if(argOp[i].type == OP_COMM) {
                // "+ 1" for the OP_INTERRUPT
                op = argOp[i].operation + 1;

                break;
            }
        }
    }

    /* ADD A FUNCTION TO GIVE checkF A VALUE */
    checkF(argc, argOp);

    // Returns the pred value in case nothing was found
    return op;
}

void errorHandler(error_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            puts("Bad usage of the function.");
            break;

        default:
            perror("[DEBUG]: Unkown error");
            break;
    };

    exit(EXIT_FAILURE);
}