#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "detect-args.h"

#include "cat.h"


int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN && argc > ARGC_MAX) errorHandler(ERROR_ARG);

    argOperation_t argOp[ARGC_MAX - 1];
    initFlags(argc, argv, argOp);
}


void initFlags(int argc, char *argv[], argOperation_t argOp[]) {
    const char *option1[] = {
        "-A",
        "-b",
        "-e",
        "-E",
        "-n",
        "-s",
        "-t",
        "-T",
        "-u",
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
        "",
        "--show-nonprinting",
        NULL
    };

    char *flags[] = {
        "--help",
        "--version",
        NULL
    };

    detectArgs(argc, argv, argOp, OP_AMOUNT, flags, option1, option2);
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
            printf("%s: ", va_arg(arg, char **));
            puts("No such file or directory.");
            break;

        default:
            perror("Unkown error.");
            break;
    }

    va_end(arg);
    exit(EXIT_FAILURE);
}