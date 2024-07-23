#ifndef __NINSTALL_H__
#define __NINSTALL_H__


// Arguments

// ninstall --help
#define ARGC_MIN 2
// ninstall new program
#define ARGC_MAX 3


// Operations

#define AMOUNT_OPERATION 3


// Error events

typedef enum {
    ERROR_ARG
}error_t;


// Functions

void errorHandler(error_t _ErrorEvent);


#endif