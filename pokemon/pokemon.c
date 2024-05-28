#include <string.h>

#include "file.h"
#include "main.h"
#include "error.h"

pokemon_t scanPkm(FILE *fp) {
    pokemon_t pkm;

    printf("Pokemon: ");
    scanstr(pkm.name, NAME_LENGTH, stdin);

    if(searchPkm(&pkm, PKM_GEN_1, fp)) {
        printf("Lv.: ");
        scanf(" %hhu", &pkm.lv);
    } else puts("The pokemon doesn't exist.");

    return pkm;
}