#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "detect-args.h"

#include "cat.h"


int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN && argc > ARGC_MAX) errorHandler(ERROR_ARG);

    // Detect the aguments operations
    argOperation_t argOp[ARGC_MAX - 1];
    initFlags(argc, argv, argOp);

    // Get the option used and compare the flags
    option_t option = checkFlags(argc, argOp);
    if(bad_usage) errorHandler(ERROR_ARG);

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

option_t checkFlags(int argc, argOperation_t argOp[]) {
    // This indicates the option used
    option_t op = (argOp[IX_ARGV_OPTION - 1].type != TYPE_FLAG)
        ?   argOp[IX_ARGV_OPTION - 1].operation
        :   NO_OPTION;

    return op;
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