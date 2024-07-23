#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

#include "detect-args.h"


// Strings
#define STR_MAX 64


// Inside functions


// Functions

uint8_t detectArgs(int argc, char *argv[], argOperation_t *argOp, uint8_t nOp, ...) {
    // Initialize the list
    va_list(op);
    va_start(op, nOp);

    char ***operations;

    va_end(op);
}