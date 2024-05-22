#include <stdint.h>
#include <stdlib.h>

#include "file.h"
#include "main.h"
#include "error.h"

void askData(FILE *fp) {
    char *str;
    if((str = (char*)malloc(sizeof(char))) == NULL) {
        fclose(fp);

        errorHandler(ERROR_MALLOC);
    }

    static uint8_t i = 0;

    puts("Put the name of the columns.");
    puts("When you are done, type [n].");

    while(str != "n" && str != "N") {
        printf("%d%c Parameters: ", ++i, GRADE);
        scanf(" %[^\n]", str);
    }

    free(str);
}