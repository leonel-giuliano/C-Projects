#include <stdlib.h>

#include "file.h"
#include "main.h"
#include "error.h"

uint8_t askData(FILE *fp) {
    char *str;
    if((str = (char*)malloc(sizeof(char))) == NULL) {
        fclose(fp);

        errorHandler(ERROR_MALLOC);
    }

    uint8_t i = 0;

    puts("Put the name of the columns.");
    puts("When you are done, type [n].");

    while(str != "n" && str != "N") {
        printf("%d%c Parameters: ", ++i, GRADE);
        scanf(" %[^\n]", str);
        fprintf(fp, "%s,", str);
        // Print the column name
    }

    fseek(fp, -1, SEEK_CUR);
    fputc('\n', fp);
    // Deletes the ',' to end the line

    free(str);
    return --i;
    // Returns the amount of columns
}