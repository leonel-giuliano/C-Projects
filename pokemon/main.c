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
        menuSetAtk,
        menuSetTgt,
        menuAtk,
        menuEnd
    };
    // All the functions the menu offers

    printf("%u. Enter the pokemon attacker.\n", MENU_SET_ATTACKER);
    printf("%u. Enter the pokemon target.\n", MENU_SET_TARGET);
    printf("%u. Calculate damage deal.\n", MENU_ATK);
    printf("%u. Close the program.\n\n", MENU_END);
    // Text with all the options

    printf("Option: ");
    scanf(" %u", state);
    while(getchar() != '\n');
    putchar('\n');
    // Scan and delete data from the terminal

    if(*state > MENU_START && *state <= MENU_END)
        menuF[*state - 1](MENU_ARG);
    else puts("Choose a given option.");

    if(*state != MENU_END) printf("\n\t++++++++++++++++++++++++++++++++++++++++\n\n");
    // Menu separator
}

void menuSetAtk(MENU_PARAM) {
    (void)targetPkm;
    pokemon_t temp;

    MENU_PRINT_OPTION("INSERT POKEMON ATTACKER");
    printf("Pokemon attacker: ");
    if(!scanPkm(&temp, fpPkm)) {
        puts("The pokemon wasn't found.");

        return;
    }

    *attackerPkm = temp;
    // Only saves it in case there wasn't a problem
    // with any pokemon so the variables are the same
    // as in the last called
}

void menuSetTgt(MENU_PARAM) {
    (void)attackerPkm;
    pokemon_t temp;

    MENU_PRINT_OPTION("INSERT POKEMON TARGET");
    printf("Pokemon target: ");
    if(!scanPkm(&temp, fpPkm)) {
        puts("The pokemon wasn't found.");

        return;
    }

    *targetPkm = temp;
}

void menuAtk(MENU_PARAM) {
    MENU_PRINT_OPTION("CALCULATOR");
}

void menuEnd(MENU_PARAM) {
    (void)attackerPkm;
    (void)targetPkm;
    (void)fpPkm;
    // Unused parameters

    puts("Closing program...");
}