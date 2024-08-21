#ifndef __NINSTALL_H__
#define __NINSTALL_H__


// Arguments

// ninstall --help
#define ARGC_MIN 2
// ninstall new app --help
#define ARGC_MAX 4


// Operations

#define AMOUNT_OP 3


// Error events
typedef enum {
    ERROR_ARG
}error_t;


void errorHandler(error_t _ErrorEvent);


#endif