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
#define OPTION_AMOUNT 9

#define has_flags argFlags.flags.flag0
#define has_option1 argFlags.flags.flag1
#define has_option2 argFlags.flags.flag2

// Types
enum {
    TYPE_FLAG = 1,
    TYPE_OPTION1,
    TYPE_OPTION2
};

// Every function command index
typedef uint8_t option_t;
enum {
    OPTION_PRED,
    OPTION_SHOW_ALL,
    OPTION_NONBLANK,
    OPTION_NONPRINT,
    OPTION_END,
    OPTION_NUMBER,
    OPTION_SQUEEZE_BLANK,
    OPTION_NONPRINT_TAB,
    OPTION_TAB,
    OPTION_NONPRINT,

    NO_OPTION
};


// Errors
typedef uint8_t error_t;
enum {
    ERROR_ARG,
    ERROR_FILE
};


void initFlags(int argc, char *argv[], argOperation_t _ArrayArgOperations[]);
void errorHandler(error_t _ErrorEvent, ...);


#endif