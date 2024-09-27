#ifndef __BULLETIN_MAIN_H__
#define __BULLETIN_MAIN_H__


#include <stdint.h>


/* FLAG */

typedef union {
    struct {
        unsigned int flag0 : 1;
        unsigned int flag1 : 1;
        unsigned int flag2 : 1;
        unsigned int flag3 : 1;
        unsigned int flag4 : 1;
        unsigned int flag5 : 1;
        unsigned int flag6 : 1;
        unsigned int flag7 : 1;
    } bits;

    uint8_t data;
} flags8_t;


/* ERROR EVENTS */

typedef uint8_t errorEvent_t;
enum {
    ERROR_FILE,
    ERROR_NOMEM,
    ERROR_READ_FILE
};


uint8_t errorHandler(errorEvent_t _ErrorEvent, ...);


#endif
