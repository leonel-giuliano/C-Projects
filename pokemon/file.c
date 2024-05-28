#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "file.h"
#include "error.h"

uint8_t searchPkm(pokemon_t *pkm, uint16_t limit, FILE *fp) {
    uint8_t found = 0;
    // Bool that checks if it was found
    uint16_t countComma = 0, countPkm = 0;

    fseek(fp, FIRST_LINE, SEEK_SET);
    char ch;
    while(!found && countPkm != limit && (ch = getc(fp)) != EOF) {
        if(ch == ',') countComma++;

        if(ch == '\n') { 
            countComma = 0;
            countPkm++;
        }
        // Resets the separator counter and increments the pokemon

        if(countComma == COMMA_NAME) {
            char str[NAME_LENGTH];
            fscanf(fp, "%[^\n,]", str);
            // Scan string until a comma or a new line

            if(!strcmp(pkm->name, str)) found = 1;
        }
    }

    if(found) {
        fgetc(fp);
        // Skip the comma between Name,Type 1

        fscanf(fp, "%[^\n,]", pkm->type[IX_TYPE_1]);
        fgetc(fp);
        // Skip the comma between Type 1,Type 2

        fscanf(fp, "%[^\n,]", pkm->type[IX_TYPE_2]);
        // The length is 1 in case it's empty
    }

    return found;
    // Returns 1 in case the wasn't any problem
    // Returns 0 if it wasn't found
}