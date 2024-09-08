#ifndef __PERSONAL_CAT_H__
#define __PERSONAL_CAT_H__


#include <stdint.h>


// Arguments

// cat [file...]
#define ARGC_MIN 2
// cat -A [file...]
#define ARGC_MAX 3


// Operations

#define OP_AMOUNT 3


// Error events
typedef uint8_t error_t;
enum {
    ERROR_ARG
};


// Contains the operations array and calls for 'checkArgs()'
// This function doesn't check for the mult options
void initFlags(int argc, char *argv[], argOp_t _ArgOperations[]);

void errorHandler(error_t _ErrorEvent);


#endif