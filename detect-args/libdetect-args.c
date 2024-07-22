#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

#include "detect-args.h"

// Operations values
#define OPERATION_COMMAND flags.flag.flag4
#define OPERATION_OPTION flags.flag.flag5

enum {
    IX_COMMAND,
    IX_OPTION
};


static flags_t flags = { 0 };


// Functions
void detectArgs(int argc, char *argv[], const char *operations, ...) {
    // Activate the flags depending on the operations passed
    if(operations[IX_COMMAND] == 'c') OPERATION_COMMAND = 1;
    if(operations[IX_OPTION] == 'o') OPERATION_OPTION = 1;

    // This is just in case of bad usage of this function
    if(!OPERATION_COMMAND && !OPERATION_OPTION) return;

    // Initialize the list of operations
    // This should be const char *[] with all the possible terms of the operations
    va_list op;
    va_start(op, operations);

    char **commands = (OPERATION_COMMAND)   ?   va_arg(op, char **)     :   NULL;
    char ***options = (OPERATION_OPTION)    ?   va_arg(op, char ***)    :   NULL;

    va_end(op);
}