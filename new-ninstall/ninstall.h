#ifndef __NINSTALL_H__
#define __NINSTALL_H__

#include "detect-args.h"


// Arguments

// ninstall --help
#define ARGC_MIN 2
// ninstall new app --help
#define ARGC_MAX 4


// Operations

#define AMOUNT_OP 3

#define has_comm argFlags.flags.flag1
#define has_option1 argFlags.flags.flag2
#define has_option2 argFlags.flags.flag3

#define IX_COMM 1

// Ix type of the operations
enum {
    OP_COMM = 1,
    OP_OPTION1,
    OP_OPTION2
};

// Tells which operation is going to be used
typedef enum {
    OP_INTERRUPT,
    OP_NEW,
    OP_EDIT,
    OP_LIST,

    OP_PRED = OP_NEW
}op_t;


// Error events
typedef enum {
    ERROR_ARG
}error_t;

// Works with the values of the argOp array to tell the type of operation per argument
// It also changes the global flags
void initFlags(int argc, char *argv[], argOperation_t _ArrayArgOperations[]);
// Calls the check functions depending on the operation
op_t checkFlags(int argc, argOperation_t _ArrayArgOperations[]);
void errorHandler(error_t _ErrorEvent);


#endif