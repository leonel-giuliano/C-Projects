#include <stdio.h>
#include <stdlib.h>

#include "argop.h"

#include "echo.h"


int main(int argc, char *argv[]) {
    // Dynamic array for the arg operations because unlimited amount of argc
    argOp_t *argOp = NULL;
    if((argOp = malloc((argc - 1) * sizeof(argOp_t))) == NULL)
        errorHandler(ERROR_MEMORY);

    free(argOp);

    return 0;
}


void initFlags(int argc, char *argv, argOp_t argOp[]) {
    const char *flag[] = {
        "--help",
        "--version",
        NULL
    };

    // "- 1" because of the mult options
    checkArgs(argc, argv, argOp, OP_AMOUNT - 1, flag);
}


void errorHandler(error_t error) {
    switch(error) {
        case ERROR_MEMORY:
            perror("Problem allocating memory.\n");
            break;

        default:
            perror("Unkown error event.\n");
            break;
    }

    exit(EXIT_FAILURE);
}