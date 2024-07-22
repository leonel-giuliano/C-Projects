#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "detect-args.h"

// Operations values
enum {
    IX_COMMAND,
    IX_OPTION
};


flags_t flags = { 0 };


// Functions
void detectArgs(int argc, char *argv[], const char *operations, ...) {
    // Initialize the list of operations
    // This should be const char *[] with all the possible terms of the operations
    va_list op;
    va_start(op, operations);

    // Declare the pointers to the list of operations
    char **commands = NULL, ***operations = NULL;



    va_end(op);
    free(commands);
    free(operations);
}