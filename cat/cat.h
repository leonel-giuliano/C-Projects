#ifndef __PERSONAL_CAT_H__
#define __PERSONAL_CAT_H__


#include <stdint.h>


/* ARGUMENTS */

// cat [file...]
#define ARGC_MIN 2
// cat [option]... [file]... --help
#define ARGC_MAX 4

enum {
    IX_COMM,
    IX_OPTION,
    IX_OPTION_FILE,

    IX_FILE = IX_OPTION_FILE - 1
};


/* OPERATIONS */

#define OP_AMOUNT 3

// "-x"
#define MULT_OP_MIN_LEN 2
// "-bEnsTv"
#define MULT_OP_MAX_LEN 7

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

// Flags for the mult options

#define has_mult_b multOpFlags.flags.flag0
#define has_mult_E multOpFlags.flags.flag1
#define has_mult_n multOpFlags.flags.flag2
#define has_mult_s multOpFlags.flags.flag3
#define has_mult_T multOpFlags.flags.flag4
#define has_mult_v multOpFlags.flags.flag5

// Value for the combine operations

#define CHECK_MULT_A() multOpFlags.data & (has_mult_v | has_mult_E | has_mult_T)
#define CHECK_MULT_e() multOpFlags.data & (has_mult_v | has_mult_E | has_mult_T)
#define CHECK_MULT_t() multOpFlags.data & (has_mult_v | has_mult_T)

#define SET_MULT_A() multOpFlags.data |= (has_mult_v | has_mult_E | has_mult_T)
#define SET_MULT_e() multOpFlags.data |= (has_mult_v | has_mult_E | has_mult_T)
#define SET_MULT_t() multOpFlags.data |= (has_mult_v | has_mult_T)

typedef union {
    struct {
        unsigned int flag0 : 1;
        unsigned int flag1 : 1;
        unsigned int flag2 : 1;
        unsigned int flag3 : 1;
        unsigned int flag4 : 1;
        unsigned int flag5 : 1;
        unsigned int flag6 : 1;
        unsigned int flag7 : 1;
    } flags;

    uint8_t data;
} multOpFlags_t;


/* ERROR EVENTS */

typedef uint8_t error_t;
enum {
    ERROR_ARG,
    ERROR_FILE
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
// Checks the flags depending on the operations used
// and checks if there was a bad usage
multOpFlags_t checkMultOp(int argc, char *argv[], argOp_t _ArgOperations[]);


/* SELECT FUNCTIONS */

// Executes the flag command given
void selectFlag(flag_t _Flag);
// Sets flags to call the multOp function
void selectOption(option_t _Option, const char *_FileName);

void errorHandler(error_t _ErrorEvent, ...);


#endif