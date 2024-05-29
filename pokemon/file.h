#ifndef __FILE_H__
#define __FILE_H__

#include <stdio.h>
#include <stdint.h>

#include "pokemon.h"

#define FIRST_LINE 352
// Number, Name, Types, Type1, Type2, Height(m), Weight(kg), Male_Pct, Female_Pct, Capt_Rate, Exp_Points, Exp_Speed, Base_Total, HP, Attack, Defense, Special, Speed, Normal_Dmg, Fire_Dmg, Water_Dmg, Eletric_Dmg, Grass_Dmg, Ice_Dmg, Fight_Dmg, Poison_Dmg, Ground_Dmg, Flying_Dmg, Psychic_Dmg, Bug_Dmg, Rock_Dmg, Ghost_Dmg, Dragon_Dmg, Evolutions,Legendary

enum {
    COMMA_ID,
    COMMA_NAME,
    COMMA_TYPES,
    COMMA_TYPE_1,
    COMMA_TYPE_2,
    COMMA_HEIGHT,
    COMMA_WEIGHT,
    COMMA_MALE_PCT,     /* Porcertage of male */
    COMMA_FEMALE_PCT,
    COMMA_PCT,
    COMMA_EXP,
    COMMA_EXP_SPEED,
    COMMA_TOTAL,
    COMMA_HP,
    COMMA_ATK,
    COMMA_DEF,
    COMMA_SP,
    COMMA_SPEED,
    COMMA_DMG_NORMAL,
    COMMA_DMG_FIRE,
    COMMA_DMG_WATER,
    COMMA_DMG_ELECTRIC,
    COMMA_DMG_GRASS,
    COMMA_DMG_ICE,
    COMMA_DMG_FIGHT,
    COMMA_DMG_POISON,
    COMMA_DMG_GROUND,
    COMMA_DMG_FLYING,
    COMMA_DMG_PSYCHIC,
    COMMA_DMG_BUG,
    COMMA_DMG_ROCK,
    COMMA_DMG_GHOST,
    COMMA_DMG_DRAGON,
    COMMA_DMG_EVO,
    COMMA_LEGENDARY
};
// Parameters

uint8_t searchPkm(pokemon_t *_Pokemon, uint16_t _PokemonAmount, FILE *_Stream);
// Returns if the pokemon was found

#endif