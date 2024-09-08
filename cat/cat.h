#ifndef __PERSONAL_CAT_H__
#define __PERSONAL_CAT_H__


#include <stdint.h>


// Arguments

// cat [file...]
#define ARGC_MIN 2
// cat -A [file...]
#define ARGC_MAX 3


// Error events
typedef uint8_t error_t;
enum {
    ERROR_ARG
};


void errorHandler(error_t _ErrorEvent);


#endif