#ifndef __BULLETIN_MAIN_H__
#define __BULLETIN_MAIN_H__


#include <stdint.h>


/* ERROR EVENTS */

typedef uint8_t errorEvent_t;
enum {
    ERROR_FILE
};


uint8_t errorHandler(errorEvent_t _ErrorEvent, ...);


#endif
