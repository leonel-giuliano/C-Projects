#ifndef __NEW_ALIAS_H__
#define __NEW_ALIAS_H__

#define COMM "new-alias"


// Arguments
#define ARGC_MIN 3
#define ARGC_MAX 5


// Error events
typedef enum {
    ERROR_ARG
}error_t;


void errorHandler(error_t _ErrorEvent);

#endif