#ifndef __MOV_FILE_H__
#define __MOV_FILE_H__

#include <stdint.h>

// Strings
#define MOVE_LENGTH 28      /* Menacing Moonraze Maelstrom */

// File properties
#define MOV_COLUMNS 55
// Name,Type,Category,Effect,Power,Acc,PP,TM,Prob.(%),Gen
enum {
    MOVF_NAME,
    MOVF_TYPE,
    MOVF_CATEGORY,
    MOVF_EFFECT,
    MOVF_POWER,
    MOVF_ACCURACY,
    MOVF_PP,
    MOVF_TM,
    MOVF_PROBABILITY,
    MOVF_GEN
};

#include "pokemon.h"

typedef struct {
    char name[MOVE_LENGTH];
    char type[TYPE_LENGTH];

    uint8_t power;
}move_t;

#endif