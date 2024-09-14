#ifndef __LS_MANAGE_H__
#define __LS_MANAGE_H__


#include <stdint.h>


/* ENUM */

typedef uint8_t flag_t;
enum {
    FLAG_HELP = 1,
    FLAG_VERSION
};


/* MANAGE */

// If there is a flag, this function calls the operation
void manageFlag(int argc, argOp_t _ArgOp[]);


#endif