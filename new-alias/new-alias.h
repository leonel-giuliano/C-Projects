#ifndef __NEW_ALIAS_H__
#define __NEW_ALIAS_H__

#include <stdint.h>


// Name of the command
#define COMM "new-alias"


// Arguments
#define ARGC_MIN 3
#define ARGC_MAX 5


// Error events
typedef enum {
    ERROR_ARG
}error_t;


// Flags
#define HAS_SUBCOMM_HELP flags.flag0
#define BAD_USAGE flags.flag1
#define HAS_SUBCOMM flags.flag2

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
    }flags;

    uint8_t data;
}flags_t;


void errorHandler(error_t _ErrorEvent);

#endif