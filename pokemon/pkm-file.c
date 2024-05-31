#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "pkm-file.h"
#include "pokemon.h"
#include "error.h"

void skipComma(uint8_t *counter, uint8_t comma, FILE *fp) {
    char ch;

    while(*counter != comma && (ch = getc(fp)) != EOF && ch != '\n')
        if(ch == ',') (*counter)++;
    // Skips to the point given
}

uint8_t searchPkm(pokemon_t *pkm, FILE *fp) {
    uint8_t found = 0;
    // Bool that checks if it was found
    uint8_t countComma = 0;

    fseek(fp, PKM_COLUMNS, SEEK_SET);
    char ch;
    while(!found && (ch = getc(fp)) != EOF) {
        if(ch == ',') countComma++;

        if(ch == '\n') countComma = 0;
        // Resets the separator counter

        if(countComma == PKMF_NAME) {
            char str[NAME_LENGTH];
            fscanf(fp, "%[^\n,]", str);
            // Scan string until a comma or a new line

            if(!strcmp(pkm->name, str)) found = 1;
        }
    }

    if(found) {
        skipComma(&countComma, PKMF_TYPE_1, fp);
        fscanf(fp, "%[^\n,]", pkm->type[IX_TYPE_1]);

        skipComma(&countComma, PKMF_TYPE_2, fp);
        fscanf(fp, "%[^\n,]", pkm->type[IX_TYPE_2]);

        for(uint8_t i = 0; i < TYPES_AMOUNT; i++) {
            skipComma(&countComma, PKMF_DMG_NORMAL + i, fp);
            // Goes to where the first damage multiplier is
            // and then only skips one comma
            
            fscanf(fp, "%f", &pkm->dmgTypes[i]);
        }
        // Save all the damage taken multipliers
        // This is for the target pokemon
    }

    return found;
    // Returns 1 in case the wasn't any problem
    // Returns 0 if it wasn't found
}