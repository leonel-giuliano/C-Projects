#include <stdio.h>
#include <stdlib.h>

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
    if((columnNames = (char*)calloc(sizeof(char), columnNum)) == NULL) {
        fclose(fpData);

        errorHandler(ERROR_MEMORY);
    }
    // Array of the column names

    free(columnNames);
    fclose(fpData);

    return 0;
}