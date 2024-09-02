#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>

#include "detect-args.h"


// Indicates the max amount of operation types
#define MAX_OP_TYPE 6

// Loops
#define LOOP_ARRAY 255


// Flags for the arguments
union _argFlags_t argFlags = { 0 };


// Inside functions
uint8_t strArrLen(const char *strArr[]) {
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

void detectArgs(int argc, char *argv[], argOperation_t argOp[], uint8_t numOp, ...) {
    // Initialize the list
    va_list(op);
    va_start(op, numOp);

    // Save the list of operations
    const char **operations[MAX_OP_TYPE];
    for(uint8_t i = 0; i < numOp; i++)
        operations[i] = va_arg(op, const char **);

    va_end(op);

    // Check the arguments one by one
    // Skip the command
    for(uint8_t i = 1; i < argc; i++) {
        // Iterate through the list of operations
        for(uint8_t j = 0; j < numOp; j++) {
            uint8_t arrLen = strArrLen(operations[j]);
            uint8_t wasFound = 0;

            // Compare the argument with every operation
            for(uint8_t k = 0; k < arrLen; k++) {
                if(!strcmp(argv[i], operations[j][k])) {
                    wasFound = 1;

                    // The "+ 1" is to take into account the NO_OPERATION
                    argOp[i - 1].type = j + 1;
                    argOp[i - 1].operation = k + 1;

                    // Activates the ix flag if the type was found
                    argFlags.data |= 1 << j;

                    break;
                }
            }

            // Stop checking for the argument if it was found
            if(wasFound) break;

            // Else, give a NO_OPERATION in the case that it wasn't found anywhere
            else if(j == numOp - 1) {
                argOp[i - 1].type = NO_OPERATION;
                argOp[i - 1].operation = NO_OPERATION;
            }
        }
    }
}