#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "detect-args.h"
#include "operation.h"

#include "cat.h"


int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN && argc > ARGC_MAX) errorHandler(ERROR_ARG);

    // Detect the aguments operations
    argOperation_t argOp[ARGC_MAX - 1];
    initFlags(argc, argv, argOp);

    // Get the option used and compare the flags
    option_t option = checkOption(argc, argOp);
    if(bad_usage) errorHandler(ERROR_ARG);

    selectOption(argv, option);

    return 0;
}


void initFlags(int argc, const char *argv[], argOperation_t argOp[]) {
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

flag_t checkFlag(int argc, argOperation_t argOp[]) {
    flag_t flag;

    // Search for the flag
    for(uint8_t i = 0; i < argc - 1; i++)
        if(argOp[i].type == TYPE_FLAG) flag = argOp[i].operation;

    return flag;
}

option_t checkOption(int argc, argOperation_t argOp[]) {
    // This indicates the option used
    option_t op = argOp[IX_ARGV_OPTION - 1].operation;
    // Offset given if it was used as pred.
    uint8_t flagPred = (op == OPTION_PRED) ? 1 : 0;

    // Check if the amount of arguments are correct
    if(argc > OPTION_MAX - flagPred) bad_usage = 1;

    // Check if there is more than one operation
    if(
        argc == OPTION_MAX - flagPred
            &&
        argOp[IX_ARGV_OPTION_FILE - flagPred].operation != NO_OPERATION
    )
        bad_usage = 1;

    return op;
}

void selectOption(const char *argv[], option_t option) {
    // Select the path that can change if the option wasn't given
    const char path[] = (has_option1 || has_option2)
        ?   argv[IX_ARGV_OPTION_FILE - 1]
        :   argv[IX_ARGV_FILE - 1];

    // Open the file for the options
    FILE *fp;
    if((fp = fopen(path, "r")) == NULL) errorHandler(ERROR_FILE);

    // Select the function depending on the option
    void (*optionF)(FILE *) = NULL;
    switch(option) {
        case OPTION_PRED ... OPTION_SHOW_ALL:
            optionF = showAllOption;
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
            puts("Bad usage of the function.");
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