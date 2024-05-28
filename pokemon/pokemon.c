#include <string.h>

#include "file.h"
#include "error.h"

uint8_t scanPkm(pokemon_t *pkm, FILE *fp) {
    uint8_t success = 0;
    pokemon_t temp;
    // In case there is an error

    printf("Pokemon: ");
    scanstr(temp.name, NAME_LENGTH, stdin);

    if(searchPkm(&temp, PKM_GEN_1, fp)) {
        printf("Lv.: ");
        scanf(" %hhu", &temp.lv);

        success = 1;
        // If the name was found and the level is correct
    }

    if(success) *pkm = temp;

    return success;
}