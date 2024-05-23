#include <stdio.h>
#include <stdint.h>
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
    char **columnNames = readRow(columnNum, fpData);
    // Array of the column names

    menuState_t menuState;
    unsigned int loopLimit = 0;
    do {
        menu(&menuState, MENU_ARG);
        loopLimit++;
    }while(menuState != MENU_END && loopLimit != MENU_LOOP);

    freeArrPtr(columnNames, columnNum);
    // Free the pointers within the array and the array itself

    fclose(fpData);

    return 0;
}

void scanstr(char str[], int max, FILE *fp) {
    fgets(str, max, fp);
    // Saves only the amount it can
    // The rest is still in the file

    size_t length = strlen(str);

    if(str[length - 1] != '\n') {
        // Checks if the end of the string is a new line
        char ch;
        while((ch = getc(fp)) != '\n' && ch != EOF);
        // Cleans the data remaining
    } else str[length - 1] = '\0';
    // Replaces the new line with end of a string
}

void freeArrPtr(char **arr, uint8_t length) {
    for(uint8_t i = 0; i < length; i++) free(arr[i]);
    free(arr);
}

void menu(menuState_t *state, MENU_PARAM) {
    void (*menuF[MENU_END])(MENU_PARAM) = {
        menuAdd,
        menuReadRow,
        menuEnd
    };
    // All the functions of the menu

    printf("%u. Add a row.\n", MENU_ADD);
    printf("%u. Print a row when inserted the number.\n", MENU_READ_ROW);
    printf("%u. Finish the program.\n\n", MENU_END);
    // Options

    printf("Write your option: ");
    scanf(" %u", state);
    while(getchar() != '\n');
    printf("\n");
    // Scans the option of the menu

    if(*state > MENU_START && *state <= MENU_END)
        menuF[*state - 1](MENU_ARG);
    // Calls the respctive function
    else puts("Choose a given option.");
}

void menuAdd(MENU_PARAM) {
    addRow(columnNames, columnNum, fpData);
}

void menuReadRow(MENU_PARAM) {
    unsigned int rowNum;
    printf("Insert the position of the row (hexadecimal): ");
    scanf(" %x", &rowNum);
    // Scan the position of the row in hexa

    rewind(fpData);
    char ch;
    unsigned int line = 1;
    while(line != rowNum && (ch = fgetc(fpData)) != EOF)
        if(ch == '\n') line++;
    // Moves the seek where the row is

    char **row = readRow(columnNum, fpData);
    for(uint8_t i = 0; i < columnNum; i++)
        printf("%s: %s\n", columnNames[i], row[i]);
    // Print every cell

    freeArrPtr(row, columnNum);
}

void menuEnd(MENU_PARAM) {
    puts("Closing program...");

    freeArrPtr(columnNames, columnNum);
    free(columnNames);
    fclose(fpData);
}