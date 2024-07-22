#ifndef __DETECT_ARGS_H__
#define __DETECT_ARGS_H__

#include <stdint.h>


// Argument data
#define NO_OPERATION 0

typedef struct {
    // Index of the type of operation used
    uint8_t type;

    // Specific index of the operation used in the operation list
    uint8_t operation;
}argOperation_t;


// Functions

// Detects in which category does every argument correspond
// _AllPosibleValues: Command - Option "co"
uint8_t detectArgs(int _NumOfArguments, char *_Arguments[], argOperation_t *_ListOfValues, uint8_t _NumOfOperations, ...);

#endif