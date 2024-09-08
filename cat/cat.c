#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "argop.h"

#include "cat.h"
#include "operation.h"


int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX) errorHandler(ERROR_ARG);

    // Check the operation of every argument
    // The "- 1" is to ignore the command
    argOp_t argOp[ARGC_MAX - 1];
    initFlags(argc, argv, argOp);

    // This is in case there was more than one operation used
    // excluding the mult operations
    if(bad_usage) errorHandler(ERROR_ARG);

    // The flags takes priority over the other operations
    if(has_flag) {
        flag_t flag = checkFlag(argc, argOp);

        selectFlag(flag);
    }

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


/* CHECK FUNCTIONS */

flag_t checkFlag(int argc, argOp_t argOp[]) {
    flag_t flag;

    // Search for the flag used
    for(uint8_t i = 0; i < argc - 1; i++) {
        if(argOp[i].type == OP_OPTION1) {
            flag = argOp[i].operation;

            break;
        }
    }

    return flag;
}

option_t checkOption(int argc, char *argv[], argOp_t argOp[]) {
    // Look for the option in a fixed place
    option_t op = (has_option1) ? argOp[IX_OPTION_FILE - 1].type : argOp[IX_FILE - 1].type;

    // Search there is no argument that uses a mult option
    for(uint8_t i = 1; i < argc; i++) {
        // Check if the arg has the min lenght
        if(strlen(argv[i]) < 2) continue;

        // Check if it is a mult option
        if(argv[i][0] == '-' && argv[i][1] != '-') bad_usage = 1;
    }

    return op;
}


/* SELECT FUNCTIONS */

void selectFlag(flag_t flag) {
    switch(flag) {
        case FLAG_HELP:
            helpFlag();
            break;

        case FLAG_VERSION:
            versionFlag();
            break;
    }
}


void errorHandler(error_t error) {
    switch(error) {
        case ERROR_ARG:
            puts("Bad usage of the cat function.\n");
            helpPred();
            break;

        default:
            perror("Unkown error.");
            break;
    }

    exit(EXIT_FAILURE);
}