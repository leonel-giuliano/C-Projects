#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "main.h"
#include "error.h"

uint8_t getColumns(FILE *fp) {
    char *str;
    if((str = (char*)malloc(sizeof(char*))) == NULL) {
        fclose(fp);

        errorHandler(ERROR_MEMORY);
    }

    uint8_t i = 0;

    puts("Put the name of the columns.");
    puts("When you are done, type [n].");

    while(strcmp(str, "n") && strcmp(str, "N")) {
        printf("%d%c Parameters: ", ++i, GRADE);
        scanf(" %[^\n]", str);

        if(strcmp(str, "n") && strcmp(str, "N"))
            fprintf(fp, "%s,", str);
        // Print the column name
    }
    // Takes as many columns as wanted until 'n' is an input

    fseek(fp, -1, SEEK_CUR);
    fprintf(fp, "%c", '\n');
    // Deletes the ',' to end the line

    free(str);
    return --i;
    // Returns the amount of columns
}

void readRow(const char *row[], FILE *fp) {
    uint8_t cells = sizeof(row) / sizeof(char*);
    // Know the amount of cells

    for(uint8_t i = 0; i < cells; i++) fscanf(fp, "[^\n,]", row[i]);
    // Reads until founds a new line or a comma
}