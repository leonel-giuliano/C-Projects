#ifndef __LIBDETECT_ARGS_H__
#define __LIBDETECT_ARGS_H__

#include <stdint.h>
#include <stdarg.h>


// Operations data

// Indicates the type wasn't found
#define NO_OPERATION 0

typedef struct {
    // Indicates the index of the type of operation
    uint8_t type;

    // Indicates the specific index of the operation
    uint8_t operation;
}argOperation_t;


// Flags

#define bad_usage argFlags.flag0

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
    } flags;
}flags_t;


// Functions

// This command tells the type and the operation of every argument
// The max ammount of posible type of operations is 7 to use the flags
// The ... should be all char *str[] and have a NULL at the end
flags_t detectArgs(int argc, char *argv[], uint8_t _NumTypeOperations, argOperation_t *_ArrayArgOperations, ...);


#endif