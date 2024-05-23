#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "file.h"
#include "error.h"

int main(int argc, char *argv[]) {
    if(argc != ARGC_PARAM) errorHandler(ERROR_ARGC);
    // Error in case wrong called program

    FILE *fpData;
    if((fpData = fopen(argv[ARGV_FILE], "r+")) == NULL)
        if((fpData = fopen(argv[ARGV_FILE], "w+")) == NULL)
            errorHandler(ERROR_FILE);
    // Uses this instead of appending to change
    // the content already written in the file

    uint8_t columnNum = getColumns(fpData);
    char *columnNames;
    if((columnNames = (char*)calloc(columnNum, sizeof(char) * STR_LENGTH)) == NULL) {
        fclose(fpData);

        errorHandler(ERROR_MEMORY);
    }
    // Array of the column names

    free(columnNames);
    fclose(fpData);

    return 0;
}

void scanstr(char str[], int max, FILE *fp) {
    uint16_t loopLimit = 0;
    fgets(str, max, fp);
    // Saves only the amount it can
    // The rest is still in the file
    size_t length = strlen(str);

    if(str[length - 1] != '\n') {
        // Checks if the end of the string is a new line
        char ch;
        while((ch = getc(fp)) != '\n' && ch != EOF && loopLimit != CH_LOOP);
        // Cleans the data remaining

        loopLimit++;
    } else str[length - 1] = '\0';
    // Replaces the new line with end of a string
}