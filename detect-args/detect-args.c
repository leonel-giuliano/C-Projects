#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

#include "detect-args.h"


// Functions

uint8_t detectArgs(int argc, char *argv[], argOperation_t *argOp, uint8_t nOp, ...) {
    // Initialize the list
    va_list(op);
    va_start(op, nOp);

    // Callocate the array of the list of operations
    char ***operations;
    if((operations = (char ***)calloc(nOp, sizeof(char **))) == NULL)
        return EXIT_FAILURE;

    // Save the list of operations
    for(uint8_t i = 0; i < nOp; i++)
        operations[i] = va_arg(op, char **);

    va_end(op);

    free(operations);
}