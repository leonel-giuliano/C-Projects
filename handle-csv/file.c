#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "main.h"
#include "error.h"

uint8_t getColumns(FILE *fp) {
    uint8_t cells = 1;
    // The 1 is to count already the new line

    rewind(fp);
    char ch = fgetc(fp);
    rewind(fp);
    // Reads only the first character

    if(ch != EOF) {
        // In case the file has data, only reads it
        while((ch = fgetc(fp)) != '\n' && ch != EOF)
            if(ch == ',') cells++;
            // Reads the amount of commas to know the cells
    } else cells = scanColumns(fp);

    rewind(fp);
    return cells;
}

uint8_t scanColumns(FILE *fp) {
    char str[STR_LENGTH];

    uint8_t i = 0;

    puts("Put the name of the columns.");
    puts("When you are done, type [n].");

    unsigned int loopLimit = 0;
    while(strcmp(str, "n") && strcmp(str, "N") && loopLimit != COLUMNS_LOOP) {
        printf("%d%c Parameters: ", ++i, GRADE);
        scanstr(str, STR_LENGTH, stdin);

        if(strcmp(str, "n") && strcmp(str, "N"))
            fprintf(fp, "%s,", str);
        // Print the column name

        loopLimit++;
    }
    // Takes as many columns as wanted until 'n' is an input

    fseek(fp, -1, SEEK_CUR);
    fprintf(fp, "%c", '\n');
    // Deletes the ',' to end the line

    fflush(fp);
    return --i;
    // Returns the amount of columns
}

char **readRow(uint8_t cells, FILE *fp) {
    char **row;
    if((row = (char**)calloc(cells, sizeof(char*))) == NULL) {
        fclose(fp);

        errorHandler(ERROR_MEMORY);
    }

    for(uint8_t i = 0; i < cells; i++) {
        char *str;
        if((str = (char*)malloc(STR_LENGTH * sizeof(char))) == NULL) {
            freeArrPtr(row, i + 1);
            fclose(fp);

            errorHandler(ERROR_MEMORY);
        }

        fscanf(fp, "%[^\n,]", str);
        // Saves the string inside the memory

        row[i] = str;
        // The position of the array saves a pointer to the string

        getc(fp);
        // Skips over separator and new line
    }
    // Reads until founds a new line or a comma

    return row;
}

void addRow(char **names, uint8_t cells, FILE *fp) {
    char str[STR_LENGTH];
    fseek(fp, 0, SEEK_END);

    for(uint8_t i = 0; i < cells; i++) {
        printf("%s: ", names[i]);
        scanstr(str, STR_LENGTH, stdin);
        fprintf(fp, "%s", str);
        // Saves the value in the file

        if(i + 1 == cells) fputc('\n', fp);
        else fputc(',', fp);
    }

    fflush(fp);
}

void printCol(uint8_t column, FILE *fp) {
    uint8_t comma = 1;

    char ch;
    while((ch = fgetc(fp)) != EOF) {
        if(ch == ',') comma++;
        // Counts the amount of separators

        if(ch == '\n') comma = 1;
        // Restart the counter per line

        if(comma == column) {
            char str[STR_LENGTH];

            fscanf(fp, "%[^\n,]", str);
            puts(str);
            // Prints the cell
        }
    }
}