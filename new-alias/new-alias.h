#ifndef __NEW_ALIAS_H__
#define __NEW_ALIAS_H__

#include <stdint.h>

// Flags
#define HAS_SUBCOMM_HELP flags.flag0
#define BAD_USAGE flags.flag1
#define HAS_SUBCOMM flags.flag2

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
// Ex: comm --list
#define ARGC_MIN 2
// Ex: comm --new alias "path" --help
#define ARGC_MAX 5

typedef enum {
    IX_COMM,
    IX_SUBCOMM,
    IX_SC_ALIAS,
    IX_SC_CODE,

    IX_ALIAS = 1,
    IX_CODE
}argvIx_t;


// Strings
#define PATH_MAX 4096
#define LINE_MAX 8192

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


subcommIx_t checkUsage(int argc, char *argv[], flags_t *_Flags);
void errorHandler(error_t _ErrorEvent);

#endif