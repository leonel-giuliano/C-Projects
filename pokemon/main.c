#include <string.h>

#include "main.h"
#include "error.h"

int main() {
    FILE *fpPkm;
    if((fpPkm = fopen(PKM_PATH, "r")) == NULL)
        errorHandler(ERROR_FILE);

    menuState_t menuState = MENU_SET;
    menu(&menuState, fpPkm);

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
    static pokemon_t playerPkm, rivalPkm;

    scanPkm(&playerPkm, fpPkm);

    printf("%s\n", playerPkm.name);
}