#ifndef __NEW_ALIAS_H__
#define __NEW_ALIAS_H__

#include "detect-args.h"


// Arguments

// Ex: new-alias list
#define ARGC_MIN 2
// Ex: new-alias new name path
#define ARGC_MAX 4


// Operations
#define AMOUNT_OPERATION 3


// Error events
typedef enum {
    ERROR_ARG
}error_t;


// Functions

void initFlags(int argc, char *argv[], argOperation_t *_ArrayArgOperations);
void errorHandler(error_t _ErrorEvent);


#endif