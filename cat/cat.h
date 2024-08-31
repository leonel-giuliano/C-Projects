#ifndef __LEO_CAT_H__
#define __LEO_CAT_H__


#include <stdarg.h>
#include <stdint.h>

#include "detect-args.h"


// Arguments

#define ARGC_MIN 2
#define ARGC_MAX 3

enum {
    IX_ARGV_COMM,
    IX_ARGV_OPTION,
    IX_ARGV_OPTION_FILE,

    IX_ARGV_FILE = IX_ARGV_OPTION
};


// Operations

#define OP_AMOUNT 2

// Same as 'has_interruption'
#define has_flags argFlags.flags.flag1
#define has_option1 argFlags.flags.flag2
#define has_option2 argFlags.flags.flag3


// Errors
typedef uint8_t error_t;
enum {
    ERROR_ARG,
    ERROR_FILE
};


void initFlags(int argc, char *argv[], argOperation_t _ArrayArgOperations[]);
void errorHandler(error_t _ErrorEvent, ...);


#endif