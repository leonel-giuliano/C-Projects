#ifndef __PERSONAL_ECHO_H__
#define __PERSONAL_ECHO_H__


#include <stdint.h>

#include "argop.h"


/* OPERATIONS */

#define OP_AMOUNT 2


/* ERROR EVENTS */

typedef uint8_t error_t;
enum {
    ERROR_MEMORY
};


// Checks the arguments operation types
void initFlags(int argc, char *argv, argOp_t _ArgOperations[]);


// Gives an EXIT_FAILURE status
void errorHandler(error_t _ErrorEvent);


#endif