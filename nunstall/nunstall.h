#ifndef __NUNSTALL_H__
#define __NUNSTALL_H__

// Arguments
#define ARGC_MIN 2
#define ARGC_MAX 4

// Error events
typedef enum {
    ERROR_ARG
}error_t;

void errorHandler(error_t _ErrorEvent);

#endif