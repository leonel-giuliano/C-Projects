#ifndef __NEW_ALIAS_H__
#define __NEW_ALIAS_H__

#include <stdint.h>

#include "subcomm.h"

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
    IX_SC_PATH,

    IX_ALIAS = 1,
    IX_PATH
}argvIx_t;


// Error events
typedef enum {
    ERROR_ARG
}error_t;


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

subcommIx_t checkUsage(int argc, char *argv[], flags_t *_Flags);
void errorHandler(error_t _ErrorEvent);

#endif