#ifndef __LEO_CAT_H__
#define __LEO_CAT_H__


#include <stdarg.h>
#include <stdint.h>


// Arguments

#define ARGC_MIN 2
#define ARGC_MAX 3

enum {
    IX_ARGV_COMM,
    IX_ARGV_FILE
};


// Errors
typedef uint8_t error_t;
enum {
    ERROR_ARG,
    ERROR_FILE
};


void errorHandler(error_t _ErrorEvent, ...);


#endif