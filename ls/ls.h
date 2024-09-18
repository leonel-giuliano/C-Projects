#ifndef __PERSONAL_LS_H__
#define __PERSONAL_LS_H__


#include <stdint.h>

#include "argop.h"


/* OPERATIONS */

#define OP_AMOUNT 4
#define MULT_OPTION_AMOUNT 39

#define has_set argFlags.flags.flag0
#define has_flag argFlags.flags.flag1
#define has_option argFlags.flags.flag2
#define has_mult argFlags.flags.flag3

// Because the bad usage isn't important for the ls command,
// is going to be used as a way to check if any operation appeared more than once
#define is_op_repeated bad_usage

enum {
    TYPE_SET = 1,
    TYPE_FLAG,
    TYPE_OPTION,
    TYPE_MULT
};


/* ERROR EVENTS */

typedef uint8_t error_t;
enum {
    ERROR_MEMORY,
    ERROR_CLOSEDIR
};


// Contains the operations and initializes the flags depending on the arguments
void initFlags(int argc, char *argv[], argOp_t _ArgOp[]);


// Exits the program in case of an error
void errorHandler(error_t _ErrorEvent, ...);


#endif