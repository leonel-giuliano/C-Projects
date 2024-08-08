#include <stdio.h>
#include <stdlib.h>

#include "new-alias.h"
#include "detect-args.h"
#include "comm.h"


int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX) errorHandler(ERROR_ARG);

    // Array that tells the type and operation for every argument
    argOperation_t argOperation[ARGC_MAX];
    initFlags(argc, argv, argOperation);

    return 0;
}

void initFlags(int argc, char *argv[], argOperation_t argOp[]) {
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

    const char *interrupt[] = {
        "-h",
        "--help",
        NULL
    };

    detectArgs(argc, argv, argOp, AMOUNT_OPERATION, interrupt, comm, option1, option2);
}

void checkUsage(int argc, argOperation_t argOp[]) {
    check_t check;

    if(has_interruption) check = CHECK_INTERRUPT;

    else if(has_comm) {
        // Check which is the ix of the operation
        for(uint8_t i = 0; i < argc - 1; i++) {
            if(argOp[i].type == OP_COMM) {
                // The "+ 1" is for the interruption
                check = argOp[i].operation + 1;

                break;
            }
        }
    }

    // Decide which check function to use depending on the args
    void (*checkF)(int, argOperation_t *) = NULL;
    switch(check) {
        case CHECK_INTERRUPT:
            checkF = checkHelp;
            break;

        default:
            // printf("Check statement value: %d\n", check);
            errorHandler(ERROR_DETECT);
            break;
    }

    checkF(argc, argOp);
}

void errorHandler(error_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            puts("There was a bad usage of the command.");
            break;

        case ERROR_DETECT:
            puts("[DEBUG] Strange outcome from the detectArgs function.");
            break;

        default:
            perror("[DEBUG] Unkown error.");
            break;
    }

    exit(EXIT_FAILURE);
}