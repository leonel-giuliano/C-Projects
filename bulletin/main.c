#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

#include "main.h"
#include "bulletin.h"


int main() {
    uint8_t retVal = 1;
    bulletin_t bulletin;

    switch(bulletinSetup(&bulletin)) {
        case SETUP_NOGOTO: return 1;
        case SETUP_MARK_NAME_LIST: goto free_mark_names;
        case SETUP_STUDENTS: goto free_students;
        case SETUP_MARK_LIST: goto free_mark_list;
        case SETUP_NOERROR: retVal = 0;
    }



    free_mark_list:
        freeAllMarks(&bulletin);

    free_students:
        free(bulletin.students);

    free_mark_names:
        freeMarkNameList(bulletin.markNameList);

        fclose(bulletin.fpData.fp);

        return retVal;
}


void menuPrint() {
    for(uint8_t i = 0; i < MENU_N_SEP; i++) putchar('-');
    puts("\n");

    PRINT_MENU_ITEM(MENU_ADD_MARK, "Add a new mark with it respective name");
    PRINT_MENU_ITEM(MENU_EDIT_MARK, "Select a student and edit the mark value");
    PRINT_MENU_ITEM(MENU_EDIT_EVERY_MARK, "Edit all of the marks");
    PRINT_MENU_ITEM(MENU_REMOVE_MARK, "Remove a mark from the bulletin");
    PRINT_MENU_ITEM(MENU_PRINT, "Prints the csv");
    PRINT_MENU_ITEM(MENU_PRINT_STUDENT, "Prints all the mark from a student");
    PRINT_MENU_ITEM(MENU_CONFIG, "Select the path for the csv file");
    PRINT_MENU_ITEM(MENU_END, "End the program");

    putchar('\n');
    for(uint8_t i = 0; i < MENU_N_SEP; i++) putchar('-');
    puts("\n");
}


char fgetsCh(char *buffer, int n, char lim, FILE *fp) {
    int i = 0;
    char ch;

    while(i < n && (ch = getc(fp)) != lim && ch != EOF)
        buffer[i++] = ch;

    buffer[i] = '\0';

    return ch;
}


char *fgetsClean(char *str, int n, FILE *fp) {
    if(fgets(str, n, fp) == NULL) return NULL;
    size_t len = strlen(str);

    // If there wasn't overflowing data, get rid of the '\n'
    if(str[len - 1] == '\n') str[len - 1] = '\0';
    // Clean the stdin
    else if(fp == stdin) CLEAN_STDIN();

    return str;
}


uint8_t errorHandler(errorEvent_t error, ...) {
    va_list arg;
    va_start(arg, error);

    printf("\nbulletin: ");

    switch(error) {
        case ERROR_FILE:
            printf("cannot access '%s': %s\n", va_arg(arg, const char *), strerror(errno));
            break;

        case ERROR_NOMEM:
            printf("problem allocating: %s\n", strerror(errno));
            break;

        case ERROR_INPUT:
            puts("problem reading the input");
            break;
    }

    va_end(arg);

    return 1;
}
