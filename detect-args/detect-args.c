#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>

#include "detect-args.h"


// Loops
#define LOOP_ARRAY 255

// Inside functions
uint8_t strArrLen(char **strArr) {
    // Count the amount of strings by searching for NULL
    uint8_t i = 0;
    uint8_t loopArray = 0;
    while(strArr[i] != NULL && loopArray != LOOP_ARRAY) {
        loopArray++;
        i++;
    }

    return i;
}


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

    // Check the arguments one by one-build
    // Skip the command
    for(uint8_t i = 1; i < argc; i++) {
        // Iterate through the list of operations
        for(uint8_t j = 0; j < nOp; j++) {
            uint8_t arrLen = strArrLen(operations[j]);
            uint8_t boolFound = 0;

            // Compare the argument with every operation
            for(uint8_t k = 0; k < arrLen; k++) {
                if(!strcmp(argv[i], operations[j][k])) {
                    // The "+ 1" is to take into account the NO_OPERATION
                    argOp[i - 1].type = j + 1;
                    argOp[i - 1].operation = k;
                    boolFound = 1;

                    break;
                }
            }

            // Stop checking for the argument if it was found
            if(boolFound) break;

            // Else, give a NO_OPERATION in the case that it wasn't found anywhere
            else if(j == nOp - 1) {
                argOp[i - 1].type = NO_OPERATION;
                argOp[i - 1].operation = NO_OPERATION;
            }
        }
    }

    free(operations);
}