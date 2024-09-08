#ifndef __PERSONAL_CAT_H__
#define __PERSONAL_CAT_H__


#include <stdint.h>


/* ARGUMENTS */

// cat [file...]
#define ARGC_MIN 2
// cat -A [file...]
#define ARGC_MAX 3

enum {
    IX_COMM,
    IX_OPTION,
    IX_OPTION_FILE,

    IX_FILE = IX_OPTION_FILE - 1
};


/* OPERATIONS */

#define OP_AMOUNT 3

#define has_flag argFlags.flags.flag0
#define has_option1 argFlags.flags.flag1

enum {
    OP_FLAG = 1,
    OP_OPTION1
};

typedef uint8_t flag_t;
enum {
    FLAG_HELP = 1,
    FLAG_VERSION
};

typedef uint8_t option_t;
enum {
    OPTION_PRED,
    OPTION_ALL,
    OPTION_NUM_NONBLANK,
    OPTION_END,
    OPTION_NUM,
    OPTION_SQZ_BLANK,
    OPTION_TAB,
    OPTION_NONPRINT
};


/* ERROR EVENTS */

typedef uint8_t error_t;
enum {
    ERROR_ARG
};


// Contains the operations array and calls for 'checkArgs()'
// This function doesn't check for the mult options
void initFlags(int argc, char *argv[], argOp_t _ArgOperations[]);


/* CHECK FUNCTIONS */

// Returns an enum of the flag operation used
flag_t checkFlag(int argc, argOp_t _ArgOperations[]);

// Returns an enum of the option operation used
// and also checks for a bad usage
option_t checkOption(int argc, char *argv[], argOp_t _ArgOperations[]);


void errorHandler(error_t _ErrorEvent);


#endif