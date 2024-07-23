#include <stdio.h>

#include "detect-args.h"


int main(int argc, char *argv[]) {
    const char *comm[] = {
        "new",
        "edit",
        NULL
    };

    const char *option1[] = {
        "-h",
        "-l",
        NULL
    };

    const char *option2[] = {
        "--help",
        "--list",
        NULL
    };

    argOperation_t argOp[3];
    detectArgs(argc, argv, argOp, 3, comm, option1, option2);

    for(int i = 1; i < argc; i++) {
        printf("Type: %d\n", argOp[i - 1].type);
        printf("Operation: %d\n\n", argOp[i - 1].operation);
    }

    return 0;
}