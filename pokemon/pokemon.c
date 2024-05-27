#include <string.h>

#include "pokemon.h"
#include "main.h"
#include "error.h"

pokemon_t *scanPkm(FILE *fp) {
    pokemon_t *pkm;
    if((pkm = (pokemon_t*)malloc(sizeof(pokemon_t))) == NULL) {
        fclose(fp);

        errorHandler(ERROR_MEMORY);
    }

    printf("Pokemon: ");
    scanstr(pkm->name, NAME_LENGTH, stdin);
    printf("Lv.: ");
    scanf(" %hhu", &pkm->lv);

    return pkm;
}