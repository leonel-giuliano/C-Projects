#ifndef __LEO_CAT_H__
#define __LEO_CAT_H__


#include <stdarg.h>
#include <stdint.h>

#include "detect-args.h"


// Arguments

// cat [file]
#define ARGC_MIN 2
// cat -A [file] --help
#define ARGC_MAX 4

// cat -A [file]
#define OPTION_MAX 3

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

// Every option command index
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
};


// Errors
typedef uint8_t error_t;
enum {
    ERROR_ARG,
    ERROR_FILE
};


// Calls the 'detectArgs' function to activate the flags
void initFlags(int argc, const char *argv[], argOperation_t _ArrayArgOperations[]);
// Checks the flags and arguments to know if the usage was correct
// and returns the option used
option_t checkOption(int argc, argOperation_t _ArrayArgOperations[]);
// Calls the option function
void selectOption(const char *argv[], option_t _Option);
void errorHandler(error_t _ErrorEvent, ...);


#endif