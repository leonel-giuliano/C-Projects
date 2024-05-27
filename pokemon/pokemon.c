#include <stdio.h>

#include "pokemon.h"

pokemon_t scanPkm(void) {
    pokemon_t pkm;

    printf("Lv. ");
    scanf(" %hhu", &pkm.lv);
    printf("Pokemon: ");

    return pkm;
}
