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


// Functions

// This command tells the type and the operation of every argument
// The ... should be all char *str[] and have a NULL at the end
uint8_t detectArgs(int argc, char *argv[], argOperation_t *_ListOfOperations, uint8_t _NumOperations, ...);


#endif