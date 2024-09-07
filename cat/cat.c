#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "detect-args.h"

#include "cat.h"
#include "operation.h"


int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN && argc > ARGC_MAX) errorHandler(ERROR_ARG);

    // Detect the aguments operations
    argOperation_t argOp[ARGC_MAX - 1];
    initFlags(argc, argv, argOp);

    // Select the function depending on the flags
    if(has_flag) {
        flag_t flag = getFlag(argc, argOp);

        selectFlag(flag, argOp);
    } else {
        option_t option = getOption(argc, argOp);
        if(bad_usage) errorHandler(ERROR_ARG);

        selectOption(argv, option);
    }

    return 0;
}


void initFlags(int argc, char *argv[], argOperation_t argOp[]) {
    const char *flags[] = {
        "--help",
        "--version",
        NULL
    };

    const char *option1[] = {
        "-A",
        "-b",
        "-e",
        "-E",
        "-n",
        "-s",
        "-t",
        "-T",
        "-v",
        NULL
    };

    const char *option2[] = {
        "--show-all",
        "--number-nonblank",
        "",
        "--show-ends",
        "--number",
        "--squeeze-blank",
        "",
        "--show-tabs",
        "--show-nonprinting",
        NULL
    };

    detectArgs(argc, argv, argOp, OP_AMOUNT, flags, option1, option2);
}

flag_t getFlag(int argc, argOperation_t argOp[]) {
    flag_t flag;

    // Search for the flag
    for(uint8_t i = 0; i < argc - 1; i++) {
        if(argOp[i].type == TYPE_FLAG) {
            flag = argOp[i].operation;

            break;
        }
    }

    return flag;
}

option_t getOption(int argc, argOperation_t argOp[]) {
    // This indicates the option used
    option_t op = argOp[IX_ARGV_OPTION - 1].operation;
    // Offset given if it was used as pred.
    uint8_t flagPred = (op == OPTION_PRED) ? 1 : 0;

    // Check if the amount of arguments are correct
    if(argc != ARGC_OPTION_AMOUNT - flagPred) bad_usage = 1;

    // Check if there is more than one operation
    if(argOp[IX_ARGV_OPTION_FILE - flagPred].operation != NO_OPERATION)
        bad_usage = 1;

    return op;
}

void selectFlag(flag_t flag, argOperation_t argOp[]) {
    switch(flag) {
        case FLAG_HELP:
            option_t op = (argOp[IX_ARGV_OPTION - 1].type == TYPE_FLAG)
                ?   OPTION_PRED
                :   argOp[IX_ARGV_OPTION - 1].operation;

            helpFlag(op);
            break;

        case FLAG_VERSION:
            versionFlag();
            break;
    }
}

void selectOption(char *argv[], option_t option) {
    // Select the path that can change if the option wasn't given
    uint8_t pathIx = (has_option1 || has_option2)
        ?   IX_ARGV_OPTION_FILE
        :   IX_ARGV_FILE;

    // Open the file for the options
    FILE *fp;
    if((fp = fopen(argv[pathIx], "r")) == NULL) errorHandler(ERROR_FILE, argv[pathIx]);

    // Select the function depending on the option
    void (*optionF)(FILE *) = NULL;
    switch(option) {
        case OPTION_PRED ... OPTION_SHOW_ALL:
            optionF = showAllOption;
            break;

        case OPTION_NONBLANK:
            optionF = numBlankOption;
            break;
    }

    optionF(fp);

    fclose(fp);
}

void errorHandler(error_t error, ...) {
    va_list arg;
    va_start(arg, error);

    printf("cat: ");

    switch(error) {
        case ERROR_ARG:
            puts("Bad usage of the function.\n\n");
            helpPred();
            break;

        case ERROR_FILE:
            // Print file name
            printf("%s: ", va_arg(arg, char *));
            puts("No such file or directory.");
            break;

        default:
            perror("Unkown error.");
            break;
    }

    va_end(arg);
    exit(EXIT_FAILURE);
}