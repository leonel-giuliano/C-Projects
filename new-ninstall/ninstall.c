#include <stdio.h>
#include <stdlib.h>

#include "detect-args.h"

#include "ninstall.h"
#include "comm.h"


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

    if(has_comm && argOp[IX_COMM - 1].type == OP_COMM)
        // The "+ 1" is bc of the interruption
        op = argOp[IX_COMM - 1].operation + 1;

    // Calls the check function
    if(!has_interruption) {
        selectCheck(checkF, op);
        checkF(argc, argOp);
    }

    // Returns the pred value in case nothing was found
    // If it has an interruption, it returns the command
    return op;
}

void selectCheck(void (*checkF)(int, argOperation_t []), op_t op) {
    switch(op) {
        case OP_NEW:
            checkF = checkNew;
            break;

        case OP_EDIT:
            checkF = checkEdit;
            break;

        case OP_LIST:
            checkF = checkList;
            break;
    }
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