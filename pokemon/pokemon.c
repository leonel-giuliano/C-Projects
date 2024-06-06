#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "pokemon.h"
#include "pkm-file.h"
#include "mov-file.h"
#include "main.h"

uint8_t scanPkm(pokemon_t *pkm, FILE *fp) {
    uint8_t success = 0;
    pokemon_t temp;
    // In case there is an error

    scanstr(temp.name, NAME_LENGTH, stdin);

    if(searchPkm(&temp, fp)) {
        printf("Lv.: ");
        scanf(" %hhu", &temp.lv);
        while(getchar() != '\n');

        while(temp.lv < MIN_LV || temp.lv > MAX_LV) {
            puts("Enter a valid level.");
            
            printf("Lv.: ");
            scanf(" %hhu", &temp.lv);
            while(getchar() != '\n');
        }
        // In case the level isn't between 1 - 100

        *pkm = temp;
        success = 1;
        // If the name was found and the level is correct
    }

    return success;
}

uint8_t scanMove(move_t *move, FILE *fp) {
    uint8_t success = 0, countComma = 0;

    scanstr(move->name, MOVE_LENGTH, stdin);

    if(searchStr(move->name, MOVF_NAME, MOV_COLUMNS, fp)) {
        exit(EXIT_FAILURE);
    }

    return success;
}