#ifndef __NEW_ALIAS_H__
#define __NEW_ALIAS_H__

#include "detect-args.h"


// Arguments

// Ex: new-alias list
#define ARGC_MIN 2
// Ex: new-alias new name path
#define ARGC_MAX 4


// Operations

#define AMOUNT_OPERATION 3

// Operation flags
#define has_comm argFlags.flags.flag1
#define has_option1 argFlags.flags.flag2
#define has_option2 argFlags.flags.flag3

enum {
    OP_COMM = 1,
    OP_OPTION1,
    OP_OPTION2
};


// Check ix
typedef enum {
    CHECK_INTERRUPT,
    CHECK_NEW,
    CHECK_EDIT,
    CHECK_REMOVE,
    CHECK_LIST
}check_t;


// Error events
typedef enum {
    ERROR_ARG,
    ERROR_DETECT
}error_t;


// Functions

// Initialize the flags depending on the arguments given
void initFlags(int argc, char *argv[], argOperation_t _ArrayArgOperations[]);
// Functions that decides which command to check
void checkUsage(int argc, argOperation_t _ArrayArgOperations[]);
void errorHandler(error_t _ErrorEvent);


#endif