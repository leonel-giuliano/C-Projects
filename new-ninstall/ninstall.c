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

    // Show the operation used in ix
    op_t op = checkFlags(argc, argOp);

    // In this case, the op is the command used with '--help'
    if(has_interruption) helpComm(op);
    else switch(op) {
        case OP_PRED:
            newComm(argv[ARG_PROGRAM]);
            break;

        case OP_NEW:
            newComm(argv[ARG_COMM_PROGRAM]);
            break;
    }

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

    char *interrupt[] = {
        "-h",
        "--help",
        NULL
    };

    detectArgs(argc, argv, argOp, AMOUNT_OP, interrupt, comm, option1, option2);
}

op_t checkFlags(int argc, argOperation_t argOp[]) {
    op_t op = OP_PRED;

    if(has_comm && argOp[IX_COMM - 1].type == OP_COMM)
        op = argOp[IX_COMM - 1].operation + 1;

    // Calls the check function
    if(!has_interruption) selectCheck(argc, argOp, op);

    // Returns the pred value in case nothing was found
    // If it has an interruption, it returns the command
    return op;
}

void selectCheck(int argc, argOperation_t argOp[], op_t op) {
    void (*checkF)(int, argOperation_t []) = NULL;

    switch(op) {
        case OP_PRED ... OP_NEW:
            checkF = checkNew;
            break;

        case OP_EDIT:
            checkF = checkEdit;
            break;

        case OP_LIST:
            checkF = checkList;
            break;
    }

    checkF(argc, argOp);
}

void errorHandler(error_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            puts("Bad usage of the function.\n");
            helpPred();
            break;

        case ERROR_HOME:
            puts("The home path couldn't be found.");
            puts("Make sure the $HOME is declared.");
            break;

        case ERROR_MEMORY:
            perror("There was a problem allocating memory.");
            break;

        default:
            perror("[DEBUG]: Unkown error");
            break;
    };

    exit(EXIT_FAILURE);
}