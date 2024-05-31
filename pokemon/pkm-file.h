#ifndef __PKM_FILE_H__
#define __PKM_FILE_H__

#include <stdio.h>
#include <stdint.h>

#include "pokemon.h"

#define PKM_COLUMNS 352
// Number, Name, Types, Type1, Type2, Height(m), Weight(kg), Male_Pct, Female_Pct, Capt_Rate, Exp_Points, Exp_Speed, Base_Total, HP, Attack, Defense, Special, Speed, Normal_Dmg, Fire_Dmg, Water_Dmg, Eletric_Dmg, Grass_Dmg, Ice_Dmg, Fight_Dmg, Poison_Dmg, Ground_Dmg, Flying_Dmg, Psychic_Dmg, Bug_Dmg, Rock_Dmg, Ghost_Dmg, Dragon_Dmg, Evolutions,Legendary
enum {
    PKMF_ID,
    PKMF_NAME,
    PKMF_TYPES,
    PKMF_TYPE_1,
    PKMF_TYPE_2,
    PKMF_HEIGHT,
    PKMF_WEIGHT,
    PKMF_MALE_PCT,     /* Porcertage of male */
    PKMF_FEMALE_PCT,
    PKMF_PCT,
    PKMF_EXP,
    PKMF_EXP_SPEED,
    PKMF_TOTAL,
    PKMF_HP,
    PKMF_ATK,
    PKMF_DEF,
    PKMF_SP,
    PKMF_SPEED,
    PKMF_DMG_NORMAL,
    PKMF_DMG_FIRE,
    PKMF_DMG_WATER,
    PKMF_DMG_ELECTRIC,
    PKMF_DMG_GRASS,
    PKMF_DMG_ICE,
    PKMF_DMG_FIGHT,
    PKMF_DMG_POISON,
    PKMF_DMG_GROUND,
    PKMF_DMG_FLYING,
    PKMF_DMG_PSYCHIC,
    PKMF_DMG_BUG,
    PKMF_DMG_ROCK,
    PKMF_DMG_GHOST,
    PKMF_DMG_DRAGON,
    PKMF_DMG_EVO,
    PKMF_LEGENDARY
};
// Parameters

void skipComma(uint8_t *_Counter, uint8_t _NumComma, FILE *_Stream);
uint8_t searchPkm(pokemon_t *_Pokemon, FILE *_Stream);
// Returns if the pokemon was found

#endif