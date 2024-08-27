#ifndef __NINSTALL_H__
#define __NINSTALL_H__

#include <stdint.h>

#include "detect-args.h"


// Arguments

// ninstall --help
#define ARGC_MIN 2
// ninstall new app --help
#define ARGC_MAX 4

enum {
    ARG_SCRIPT,
    ARG_PROGRAM,

    ARG_COMM = 1,
    ARG_COMM_PROGRAM
};


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
typedef uint8_t op_t;
enum {
    OP_PRED,
    
    OP_NEW,
    OP_EDIT,
    OP_LIST,
};


// Error events
typedef uint8_t error_t;
enum {
    ERROR_ARG,
    ERROR_HOME,
    ERROR_MEMORY
};

// Works with the values of the argOp array to tell the type of operation per argument
// It also changes the global flags
void initFlags(int argc, char *argv[], argOperation_t _ArrayArgOperations[]);
// Calls the check functions depending on the operation
op_t checkFlags(int argc, argOperation_t _ArrayArgOperations[]);
// Selects the check function
void selectCheck(int argc, argOperation_t _ArrayArgOperations[], op_t _Operation);
void errorHandler(error_t _ErrorEvent);


#endif