#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "main.h"
#include "error.h"

uint8_t askData(FILE **fp) {
    char *str;
    if((str = (char*)malloc(sizeof(char))) == NULL) {
        fclose(*fp);

        errorHandler(ERROR_MALLOC);
    }

    uint8_t i = 0;

    puts("Put the name of the columns.");
    puts("When you are done, type [n].");

    while(strcmp(str, "n") && strcmp(str, "N")) {
        printf("%d%c Parameters: ", ++i, GRADE);
        scanf(" %[^\n]", str);

        if(strcmp(str, "n") && strcmp(str, "N"))
            fprintf(*fp, "%s,", str);
        // Print the column name
    }
    // Takes as many columns as wanted until 'n' is an input

    fseek(*fp, -1, SEEK_CUR);
    fprintf(*fp, "%c", '\n');
    // Deletes the ',' to end the line

    free(str);
    return --i;
    // Returns the amount of columns
}