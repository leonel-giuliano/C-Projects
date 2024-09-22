#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

#include "bulletin.h"
#include "student.h"
#include "file.h"


int main() {
    uint8_t retVal = 0;
    bulletin_t bulletin;

    // Open the file and get the amount of students
    // It either asks the user or reads it from the file
    if(fopenLen(&bulletin) == -1) return errorHandler(ERROR_FILE, bulletin.pathStr);
    if(!bulletin.len) {
        retVal = errorHandler(ERROR_INPUT);
        goto close_file;
    }

    // Initialize the array of students
    if((bulletin.students = (student_t *)malloc(bulletin.len * sizeof(student_t))) == NULL) {
        retVal = errorHandler(ERROR_NOMEM);
        goto close_file;
    }


    free_students:
        free(bulletin.students);

    close_file:
        fclose(bulletin.file);

        return retVal;
}


int8_t fopenLen(bulletin_t *bulletin) {
    bulletin->is_fcreated = 0;

    // Try to open the file if it exists
    if((bulletin->file = fopen(getDir(bulletin->pathStr), "r+")) == NULL) {
        if((bulletin->file = fopen(bulletin->pathStr, "w+")) == NULL)
            return -1;

        bulletin->len = asknStudents();
        bulletin->is_fcreated = 1;
    }
    // The amount of students is taken from the file
    // If it didn't have any student, asks the user
    else if(!(bulletin->len = fgetnStudents(bulletin->file)))
        bulletin->len = asknStudents();

    return bulletin->is_fcreated;
}


char *fgetsClean(char *dest, int n, FILE *fp) {
    // It couldn't read anything
    if(!fgets(dest, n, fp)) return NULL;
    size_t len = strlen(dest);

    // Get rid of the new line
    if(dest[len - 1] == '\n') dest[len - 1] = '\0';

    // Clean the stdin in case of input buffer
    else if(fp == stdin) {
        char ch;
        while((ch = getchar()) != '\n' && ch != EOF);
    }

    return dest;
}


uint8_t errorHandler(errorEvent_t error, ...) {
    va_list arg;
    va_start(arg, error);

    printf("bulletin: ");

    switch(error) {
        case ERROR_INPUT:
            puts("it seems there was a problem in the input");
            break;

        case ERROR_FILE:
            printf("cannot access '%s': %s\n", va_arg(arg, const char *), strerror(errno));
            break;

        case ERROR_NOMEM:
            printf("problem allocating: %s\n", strerror(errno));
    }

    va_end(arg);

    return 1;
}