#ifndef __NEW_ALIAS_H__
#define __NEW_ALIAS_H__

#include <stdint.h>

// Flags
#define HAS_SUBCOMM_HELP flags.flag0
#define BAD_USAGE flags.flag1
#define HAS_SUBCOMM flags.flag2
#define HAS_OPTION flags.flag3

typedef union {
    uint8_t data;

    struct {
        unsigned int flag0 : 1;
        unsigned int flag1 : 1;
        unsigned int flag2 : 1;
        unsigned int flag3 : 1;
        unsigned int flag4 : 1;
        unsigned int flag5 : 1;
        unsigned int flag6 : 1;
        unsigned int flag7 : 1;
    }flags;
}flags_t;

// Name of the command
#define COMM "new-alias"


// Arguments
// Ex: comm --help
#define ARGC_MIN 2
// Ex: comm --new alias --static path --help
#define ARGC_MAX 6

typedef enum {
    IX_COMM,
    IX_SUBCOMM,
    IX_SC_ALIAS,
    IX_SC_OPTION,
    IX_SC_OP_CODE,

    IX_SC_CODE = IX_SC_OPTION,

    IX_ALIAS = IX_SUBCOMM,
    IX_OPTION,
    IX_OP_CODE,

    IX_CODE = IX_OP_CODE
}argvIx_t;

#define COMM_FUNCTIONS 2

typedef enum {
    IX_COMM_SUBCOMM,
    IX_COMM_OPTION
}commIx_t;


// Strings
#define PATH_MAX 4096
#define LINE_MAX 8192
#define ALIAS_COMMENT_LENGTH 18

#define BASH_FILE "/.bashrc-test"
#define BASH_TEMP "/.bashrc-temp"
#define ALIAS_COMMENT "# Personal Alias\n"


// Loops
#define LOOP_BASH 4096


// Error events
typedef enum {
    ERROR_ARG,

    ERROR_OPEN_BASH,
    ERROR_BASH_TEMP,
    ERROR_MEMORY,

    ERROR_SUBCOMM
}error_t;


#include "subcomm.h"
#include "option.h"


void checkUsage(int argc, char *argv[], flags_t *_Flags, uint8_t *_CommandArray);
void errorHandler(error_t _ErrorEvent);


extern const char *optionArray[AMOUNT_OPTION][SAME_OPTION];

#endif