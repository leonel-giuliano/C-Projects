#ifndef __POKEMON_H__
#define __POKEMON_H__

#include <stdio.h>
#include <stdint.h>

#define TYPES_AMOUNT 15
#define MIN_LV 1
#define MAX_LV 100

// String length
#define NAME_LENGTH 18      /* HoopaHoopa Unbound */
#define TYPE_LENGTH 9       /* Electric */

// Pokemon struct
#define TYPE_PER_PKM 2
enum {
    IX_TYPE_1,
    IX_TYPE_2
};
// Array index

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