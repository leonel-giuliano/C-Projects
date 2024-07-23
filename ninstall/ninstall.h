#ifndef __NINSTALL_H__
#define __NINSTALL_H__


// Arguments

// ninstall --help
#define ARGC_MIN 2
// ninstall new program
#define ARGC_MAX 3


// Operations

#define AMOUNT_OPERATION 3

enum {
    IX_NONE,
    IX_COMMAND,
    IX_OPTION1,
    IX_OPTION2
};


// Error events
typedef enum {
    ERROR_ARG,

    ERROR_MEMORY
}error_t;


// Functions

void errorHandler(error_t _ErrorEvent);


#endif