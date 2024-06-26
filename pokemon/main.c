#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "main.h"
#include "pokemon.h"
#include "mov-file.h"
#include "error.h"

int main() {
    FILE *fpPkm, *fpMove;
    if((fpPkm = fopen(PKM_PATH, "r")) == NULL || (fpMove = fopen(MOVE_PATH, "r")) == NULL)
        errorHandler(ERROR_FILE);

    menuState_t menuState;
    uint8_t loopLim = 0;
    do {
        menu(&menuState, fpPkm, fpMove);
        loopLim++;
    }while(menuState != MENU_END && loopLim != LIMIT_MENU);

    fclose(fpPkm);
    fclose(fpMove);

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

void menu(menuState_t *state, FILE *fpPkm, FILE *fpMove) {
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

void setPkm(pokemon_t *pkm, const char *role, FILE *fp) {
    pokemon_t temp;
    char str[] = "INSERT POKEMON ";
    strcat(str, role);

    MENU_PRINT_OPTION(str);
    printf("Pokemon %s: ", role);
    if(!scanPkm(&temp, fp)) {
        puts("The pokemon wasn't found.");

        return;
    }

    *pkm = temp;
    // Only saves it in case there wasn't a problem
    // with any pokemon so the variables are the same
    // as in the last called
}

void menuSetAtk(MENU_PARAM) {
    (void)fpMove;
    (void)targetPkm;

    setPkm(attackerPkm, "ATTACKER", fpPkm);
}

void menuSetTgt(MENU_PARAM) {
    (void)fpMove;
    (void)attackerPkm;

    setPkm(targetPkm, "TARGET", fpPkm);
}

void menuAtk(MENU_PARAM) {
    (void)fpPkm;
    move_t move;

    MENU_PRINT_OPTION("CALCULATOR");
    scanMove(&move, fpMove);
}

void menuEnd(MENU_PARAM) {
    (void)attackerPkm;
    (void)targetPkm;
    (void)fpPkm;
    // Unused parameters

    puts("Closing program...");
}