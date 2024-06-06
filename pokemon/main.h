#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <string.h>

#include "pokemon.h"

#define PKM_PATH "./pokemon.csv"
#define MOVE_PATH "./moves.csv"

// MENU
#define MENU_PRINT_OPTION(str) printf("\t\t-----   %s   -----\n", str);
#define MENU_PARAM pokemon_t *attackerPkm, pokemon_t *targetPkm, FILE *fpPkm, FILE *fpMove
#define MENU_ARG &attackerPkm, &targetPkm, fpPkm, fpMove
typedef enum {
    MENU_START,
    MENU_SET_ATTACKER,
    MENU_SET_TARGET,
    MENU_ATK,
    MENU_END
}menuState_t;

void scanstr(char *_Buffer, size_t _MaxLength, FILE *_Stream);
void setPkm(pokemon_t *_Pokemon, const char *_Str, FILE *_Stream);

// MENU FUNCTIONS
void menu(menuState_t *_State, FILE *_StreamPkm, FILE *_StreamMove);
void menuSetAtk(MENU_PARAM);
void menuSetTgt(MENU_PARAM);
void menuAtk(MENU_PARAM);
void menuEnd(MENU_PARAM);

#endif