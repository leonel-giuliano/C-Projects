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
#define ARGC_OPTION_AMOUNT 3

enum {
    IX_ARGV_COMM,
    IX_ARGV_OPTION,
    IX_ARGV_OPTION_FILE,

    IX_ARGV_FILE = IX_ARGV_OPTION
};


// Operations

#define OP_AMOUNT 2
#define OPTION_AMOUNT 9

#define has_flag argFlags.flags.flag0
#define has_option1 argFlags.flags.flag1
#define has_option2 argFlags.flags.flag2

// Types
enum {
    TYPE_FLAG = 1,
    TYPE_OPTION1,
    TYPE_OPTION2
};

typedef uint8_t flag_t;
enum {
    FLAG_HELP = 1,
    FLAG_VERSION
};

typedef uint8_t option_t;
enum {
    OPTION_PRED,
    OPTION_SHOW_ALL,
    OPTION_NONBLANK,
    OPTION_NONPRINT_END,
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
void initFlags(int argc, char *argv[], argOperation_t _ArrayArgOperations[]);


// Returns the flag used
flag_t getFlag(int argc, argOperation_t argOp[]);

// Checks if the usage was correct and returns the option used
option_t getOption(int argc, argOperation_t _ArrayArgOperations[]);


// Calls the flag function
void selectFlag(flag_t flag, argOperation_t argOp[]);

// Calls the option function
void selectOption(char *argv[], option_t _Option);


void errorHandler(error_t _ErrorEvent, ...);


#endif