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

#define bad_usage argFlags.flags.flag0
#define has_interruption argFlags.flags.flag7

union _argFlags_t {
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
};

extern union _argFlags_t argFlags;


// Functions

// This command tells the type and the operation of every argument
// The max ammount of posible type of operations is 6 to use the flags
// The ammount of operations inside a type goes up to 255
// The ... should be all char *str[] and have a NULL at the end
void detectArgs(int argc, char *argv[], argOperation_t _ArrayArgOperations[], uint8_t _NumTypeOperations, char *_ArrayInterruptions[], ...);


#endif