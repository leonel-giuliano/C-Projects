#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>

#include "detect-args.h"


// Loop limits
#define LOOP_STR 255


// Inside functions
uint8_t strArrayLen(const char **strArray) {
    uint8_t i = 0, loopStr = 0;
    while(strArray[i] != NULL && loopStr != LOOP_STR) {
        loopStr++;
        i++;
    }

    return i;
}


// Functions
void detectArgs(int argc, char *argv[], argOperation_t *list, uint8_t numOp, ...) {
    // Initialize the list of operations
    va_list(op);
    va_start(op, numOp);

    // Check argument by argument skipping the file command
    for(uint8_t i = 1; i < argc; i++) {
        // Repeat the amount of operations passed
        for(uint8_t j = 0; j < numOp; j++) {
            // Get the string array and the lenght
            const char **strArray = va_arg(op, const char **);
            uint8_t strLen = strArrayLen(strArray);
            uint8_t boolFound = 0;

            // Compare the argument with the list of operations
            for(uint8_t k = 0; k < strLen; k++) {
                if(!strcmp(argv[i], strArray[k])) {
                    boolFound = 1;
                    // Save the index inside the list
                    // The "+ 1" is to give space for the none operation value
                    list[i - 1].type = j + 1;
                    list[i - 1].operation = k;

                    break;
                }
            }

            // Stop searching in the other operation lists in the
            // case the operation was found
            if(boolFound) break;

            // This checks if it wasn't found at any point
            else if (j == numOp - 1) {
                list[i - 1].type = NO_OPERATION;
                list[i - 1].operation = NO_OPERATION;
            }
        }
    }

    va_end(op);
}