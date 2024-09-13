#include <stdio.h>
#include <stdarg.h>
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
    
    else if(has_option1) {
        option_t op = checkOption(argc, argv, argOp);

        if(!bad_usage) selectOption(op, argv[IX_OPTION_FILE]);
    }
    
    else {
        // Check if it isn't a mult option
        if(argv[IX_OPTION][0] != '-' && argc >= ARGC_PRED_MIN && argc <= ARGC_PRED_MAX)
            selectOption(OPTION_PRED, argv[IX_FILE]);

        // Check if it is a mult option
        else if(argv[IX_OPTION][0] == '-' && argc >= ARGC_OPTION_MIN && argc <= ARGC_OPTION_MAX) {
            multOpFlags_t multOpFlags = checkMultOp(argc, argv, argOp);

            if(!bad_usage) multOp(multOpFlags, argv[IX_OPTION_FILE]);
        } else bad_usage = 1;
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
    option_t op = argOp[IX_OPTION - 1].type;

    if(argc < ARGC_OPTION_MIN || argc > ARGC_OPTION_MAX) bad_usage = 1;

    // Search there is no argument that uses a mult option
    else for(uint8_t i = 1; i < argc; i++) {
        // Check if the arg has the min lenght "-x"
        // Check if it is a mult option
        if(strlen(argv[i]) >= MULT_OP_MIN_LEN && argv[i][0] == '-' && argv[i][1] != '-')
            bad_usage = 1;
    }

    return op;
}

multOpFlags_t checkMultOp(int argc, char *argv[], argOp_t argOp[]) {    
    size_t multOpLen = strlen(argv[IX_OPTION]);
    multOpFlags_t multOpFlags = { 0 };

    // Check if the mult op is greater than the possible amount of options
    if(multOpLen > MULT_OP_MAX_LEN) bad_usage = 1;

    // Check if the other arguments are an operation
    else for(uint8_t i = IX_OPTION; i < argc - 1; i++)
        if(argOp[i].type != NOT_FOUND) bad_usage = 1;

    if(bad_usage) return multOpFlags;

    // Iterate through every char of the mult option
    // Skip the '-' char
    for(uint8_t i = 1; i < multOpLen; i++) {
        // Check the value of the char
        switch(argv[IX_OPTION][i]) {
            case 'A':
            case 'e':
                if(CHECK_MULT_A()) bad_usage = 1;
                SET_MULT_A();

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
                if(CHECK_MULT_t()) bad_usage = 1;
                SET_MULT_t();

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

    return multOpFlags;
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

void selectOption(option_t op, const char *name) {
    // Manage the multOp flags to call the principal function
    multOpFlags_t multOpFlags = { 0 };

    // Only combined option
    if(op == OPTION_ALL) SET_MULT_A();
    // Check according to the ix of flag starting with '-b'
    else if(op != OPTION_PRED)
        multOpFlags.data |= 1 << op - OPTION_NUM_NONBLANK;

    multOp(multOpFlags, name);
}


void errorHandler(error_t error, ...) {
    va_list arg;
    va_start(arg, error);

    switch(error) {
        case ERROR_ARG:
            puts("Bad usage of the cat function.\n");
            helpFlag();

            break;

        case ERROR_FILE:
            printf("cat: %s: No such file or directory.\n", va_arg(arg, const char *));
            break;

        default:
            perror("Unkown error.");
            break;
    }

    va_end(arg);

    exit(EXIT_FAILURE);
}