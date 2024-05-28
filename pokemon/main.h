#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>

#include "pokemon.h"

#define PKM_PATH "./pokemon.csv"

// MENU
#define MENU_PARAM pokemon_t *playerPkm, pokemon_t *rivalPkm, FILE *fpPkm
#define MENU_ARG *playerPkm, *rivalPkm, *fpPkm
typedef enum {
    MENU_START,
    MENU_SET,
    MENU_END
}menuState_t;

void scanstr(char *_Buffer, size_t _MaxLength, FILE *_Stream);

void menu(menuState_t *_State, FILE *_Stream);
void menuSet(MENU_PARAM);

#endif