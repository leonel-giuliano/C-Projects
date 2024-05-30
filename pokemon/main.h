#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <string.h>

#include "pokemon.h"

#define PKM_PATH "./pokemon.csv"

// MENU
#define MENU_PRINT_OPTION(str) printf("\t-----   %s   -----\n", str)
// Print the title of the option chosen
#define MENU_PARAM pokemon_t *attackerPkm, pokemon_t *targetPkm, FILE *fpPkm
#define MENU_ARG &attackerPkm, &targetPkm, fpPkm
typedef enum {
    MENU_START,
    MENU_SET_ATTACKER,
    MENU_SET_TARGET,
    MENU_ATK,
    MENU_END
}menuState_t;

void scanstr(char *_Buffer, size_t _MaxLength, FILE *_Stream);

// MENU FUNCTIONS
void menu(menuState_t *_State, FILE *_Stream);
void menuSetAtk(MENU_PARAM);
void menuSetTgt(MENU_PARAM);
void menuAtk(MENU_PARAM);
void menuEnd(MENU_PARAM);

#endif