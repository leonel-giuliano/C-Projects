#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "main.h"
#include "error.h"

int main() {
    FILE *fpPkm;
    if((fpPkm = fopen(PKM_PATH, "r")) == NULL)
        errorHandler(ERROR_FILE);

    menuState_t menuState;
    uint8_t loopLim = 0;
    do {
        menu(&menuState, fpPkm);
        loopLim++;
    }while(menuState != MENU_END && loopLim != LIMIT_MENU);

    fclose(fpPkm);

    return 0;
}

void scanstr(char *str, size_t max, FILE *fp) {
    fgets(str, max, fp);
    size_t length = strlen(str);

    if(str[length - 1] != '\n') {
        char ch;
        while((ch = getc(fp)) != '\n' && ch != EOF);
    } else str[length - 1] = '\0';
}

void menu(menuState_t *state, FILE *fpPkm) {
    static pokemon_t attackerPkm, targetPkm;

    void (*menuF[MENU_END])(MENU_PARAM) = {
        menuSet,
        menuEnd
    };

    printf("Option: ");
    scanf(" %u", state);
    while(getchar() != '\n');
    // Scan and delete data from the terminal

    if(*state > MENU_START && *state <= MENU_END)
        menuF[*state - 1](MENU_ARG);
    else puts("Choose a given option.");

    printf("%s\n", attackerPkm.type[IX_TYPE_1]);
}

void menuSet(MENU_PARAM) {
    pokemon_t tempAtk, tempTarget;
    // In case there is a problem

    printf("Pokemon attacker: ");
    if(!scanPkm(&tempAtk, fpPkm)) {
        puts("The pokemon wasn't found.");

        return;
    }

    printf("Pokemon target: ");
    if(!scanPkm(&tempTarget, fpPkm)) {
        puts("The pokemon wasn't found.");

        return;
    }

    *attackerPkm = tempAtk;
    *targetPkm = tempTarget;
    // Only saves it in case there wasn't a problem
    // with any pokemon so the variables are the same
    // as in the last called
}

void menuEnd(MENU_PARAM) {
    (void)attackerPkm;
    (void)targetPkm;
    (void)fpPkm;
    // Unused parameters

    puts("Closing program...");
}