#ifndef __NINSTALL_H__
#define __NINSTALL_H__

#define ARGC_MAX 3 /* Max amount of arguments */

// All posible errors that exit the code
typedef enum {
    ERROR_ARG
}errorEvent_t;

void errorHandler(errorEvent_t _ErrorEvent);

#endif