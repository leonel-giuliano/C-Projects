#ifndef __POKEMON_H__
#define __POKEMON_H__

#include <stdio.h>
#include <stdint.h>

#include "pkm-file.h"

#define PKM_GEN_1 151

// String length
#define NAME_LENGTH 19      /* HoopaHoopa Unbound */
#define TYPE_LENGTH 9       /* Electric */

// Pokemon struct
#define TYPES_AMOUNT 15
#define TYPE_PER_PKM 2
#define MIN_LV 1
#define MAX_LV 100
#define IX_DMG_TYPE(type) (type - PKMF_DMG_NORMAL)
// The type has to be also from the enum to get the index
enum {
    IX_TYPE_1,
    IX_TYPE_2
};
// Types index

typedef struct {
    uint8_t lv;
    char name[NAME_LENGTH];
    char type[TYPE_PER_PKM][TYPE_LENGTH];

    uint8_t damage;
    uint8_t defense;

    float dmgTypes[TYPES_AMOUNT];
    // Damaged received from a type
}pokemon_t;

uint8_t scanPkm(pokemon_t *_Pokemon, FILE *_Stream);

#endif