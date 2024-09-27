#ifndef __PURA_GARRA_MAIN_H__
#define __PURA_GARRA_MAIN_H__


#include <stdint.h>


typedef uint8_t errorEvent_t;


void errorHandler(errorEvent_t _ErrorEvent, ...);


#endif