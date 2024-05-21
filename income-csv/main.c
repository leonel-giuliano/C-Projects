#include <stdio.h>
#include <string.h>

#include "main.h"
#include "list.h"
#include "error.h"

int main(int argc, char *argv[]) {
    if(argc > ARGC_FILE) errorHandler(ERROR_ARGC);

    char *filePath = getPath(argc, argv);
    FILE *fpIncome;
    if((fpIncome = fopen(filePath, "w+")) == NULL)
        errorHandler(ERROR_FILE);
    // Opens the file with the indicated path

    addItem(fpIncome);

    delList();
    fclose(fpIncome);

    return 0;
}

char *getPath(int argc, char *argv[]) {
    char *path;

    if(argc == ARGC_PRED) path = FILE_PRED;
    // In case the file wasn't passed
    else {
        size_t len = strlen(argv[ARGV_FILE]);
        size_t typeLen = strlen(FILE_TYPE);
        // Variables to compare only the type of the file

        if(!strcmp(argv[ARGV_FILE] + len - typeLen, FILE_TYPE))
            path = argv[ARGV_FILE];
        else errorHandler(ERROR_FILE_TYPE);
        // Throws an error in case the file isn't '.csv'
    }

    return path;
}

void scanStr(char *str, size_t num, FILE *fp) {
    fgets(str, num, fp);
    size_t len = strlen(str);

    if(str[len - 1] != '\n') {
        // Case where the string is bigger than the buffer
        char ch;
        while((ch = getc(fp)) != '\n' && ch != EOF);
        // Skips the overflowing data
    } else str[len - 1] == '\0';
}