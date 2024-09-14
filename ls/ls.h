#ifndef __PERSONAL_LS_H__
#define __PERSONAL_LS_H__


#include <stdint.h>

#include "argop.h"


/* OPERATIONS */

#define OP_AMOUNT 4

#define has_set argFlags.flags.flag0
#define has_flag argFlags.flags.flag1
#define has_option argFlags.flags.flag2
#define has_mult argFlags.flags.flag3


/* ERROR EVENTS */

typedef uint8_t error_t;
enum {
    ERROR_MEMORY
};


// Contains the operations and initializes the flags depending on the arguments
void initFlags(int argc, char *argv[], argOp_t _ArgOp[]);


// Exits the program in case of an error
void errorHandler(error_t _ErrorEvent);


#endif