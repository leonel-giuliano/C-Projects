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

    // The flags takes priority over the other operations
    if(has_flag) {
        flag_t flag = checkFlag(argc, argOp);

        selectFlag(flag);
    }

    if(bad_usage) errorHandler(ERROR_ARG);

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
        if(argOp[i].type == OP_FLAG) {
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
        // Check if the arg has the min lenght "-x"
        // Check if it is a mult option
        if(strlen(argv[i]) >= MULT_OP_MIN_LEN && argv[i][0] == '-' && argv[i][1] != '-')
            bad_usage = 1;
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

void selectMultOption(int argc, char *argv[]) {    
    size_t multOpLen = strlen(argv[IX_OPTION]);
    multOpFlags_t multOpFlags = { 0 };

    // Check if the lenght is greater than the possible amount
    // of mult options used at once
    if(multOpLen > MULT_OP_MAX_LEN) {
        bad_usage = 1;

        return;
    }

    // Iterate through every char of the mult option
    for(uint8_t i = 1; i < multOpLen; i++) {
        // Check the value of the char
        switch(argv[IX_OPTION][i]) {
            case 'A':
            case 'e':
                if(has_mult_v || has_mult_E || has_mult_T)
                    bad_usage = 1;

                has_mult_v = 1;
                has_mult_E = 1;
                has_mult_T = 1;

                break;

            case 'b':
                if(has_mult_b) bad_usage = 1;
                has_mult_b = 1;

                break;

            case 'E':
                if(has_mult_E) bad_usage = 1;
                has_mult_E = 1;

                break;

            case 'n':
                if(has_mult_n) bad_usage = 1;
                has_mult_n = 1;

                break;

            case 's':
                if(has_mult_s) bad_usage = 1;
                has_mult_s = 1;

                break;

            case 't':
                if(has_mult_v || has_mult_T) bad_usage = 1;
                has_mult_v = 1;
                has_mult_T = 1;

                break;

            case 'T':
                if(has_mult_T) bad_usage = 1;
                has_mult_T = 1;

                break;

            case 'u': break;

            case 'v':
                if(has_mult_v) bad_usage = 1;
                has_mult_v = 1;

                break;

            default: bad_usage = 1;
        }
    }
}


void errorHandler(error_t error) {
    switch(error) {
        case ERROR_ARG:
            puts("Bad usage of the cat function.\n");
            helpFlag();
            break;

        default:
            perror("Unkown error.");
            break;
    }

    exit(EXIT_FAILURE);
}