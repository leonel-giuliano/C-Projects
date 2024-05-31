#ifndef __MOV_FILE_H__
#define __MOV_FILE_H__

#include <stdint.h>

#include "pokemon.h"

#define MOVE_LENGTH 13      /* Selfdestruct */

typedef struct {
    char name[MOVE_LENGTH];
    char type[TYPE_LENGTH];

    uint8_t power;
}move_t;

#endif