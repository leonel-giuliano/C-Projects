#ifndef __NINSTALL_H__
#define __NINSTALL_H__


#include <stdint.h>

#include "argop.h"


/* ARGUMENTS */

// ninstall [PROGRAM]
#define ARGC_MIN 2

// ninstall [OPTION] [PROGRAM] [FLAG]
#define ARGC_MAX 4


/* OPERATIONS */

#define OP_AMOUNT 2


/* ERROR EVENTS */

typedef uint8_t error_t;
enum {
    ERROR_ARG
};


// Check the arguments operation to initializate 'argFlags' and save
// the type and operation in the '_ArgOp[]'
void initFlags(int argc, char *argv[], argOp_t _ArgOp[]);

// Give an exit failure when is called and print an error msg depending on the event
void errorHandler(error_t _ErrorEvent);


#endif