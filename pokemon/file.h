#include <stdio.h>
#include <stdint.h>

#include "main.h"

#define FIRST_LINE 89
// "#,Name,Type 1,Type 2,Total,HP,Attack,Defense,Sp. Atk,
// Sp. Def,Speed, Generation,Legendary" + '\n'

enum {
    COMMA_ID,
    COMMA_NAME,
    COMMA_TYPE_1,
    COMMA_TYPE_2,
    COMMA_TOTAL,
    COMMA_HP,
    COMMA_ATK,
    COMMA_DEF,
    COMMA_SP_ATK,
    COMMA_SP_DEF,
    COMMA_SPEED,
    COMMA_GEN,
    COMMA_LEGENDARY
};
// Parameters

uint8_t searchPkm(pokemon_t *_Pokemon, uint16_t _PokemonAmount, FILE *_Stream);
// Returns if the pokemon was found