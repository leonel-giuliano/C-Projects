#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

#include "bulletin.h"
#include "file.h"
#include "student.h"


int main() {
    uint8_t retVal = 0;

    bulletin_t bulletin = initBt();
    if(getPath(bulletin.fpData.path) == NULL) return errorHandler(ERROR_FILE, CONFIG_PATH);
    if(fopenBt(&bulletin.fpData) == NULL) return errorHandler(ERROR_FILE, bulletin.fpData.path);

    if(bulletin.fpData.was_read) fgetnStudents(&bulletin);
    
    // Ask the user if there was no file or it didn't have the students
    // Throw error if there was a problem reading the stdin
    if(!bulletin.fpData.has_students && !(bulletin.len = asknStudents())) {
        retVal = errorHandler(ERROR_INPUT);
        goto close_file;
    }

    if((bulletin.students = (student_t *)malloc(bulletin.len * sizeof(student_t))) == NULL) {
        retVal = errorHandler(ERROR_MALLOC);
        goto close_file;
    }


    free_students:
        free(bulletin.students);

    close_file:
        fclose(bulletin.fpData.fp);

        return retVal;
}


bulletin_t initBt() {
    bulletin_t b;

    b.len = 0;
    b.markNameList = NULL;
    b.students = NULL;
    b.fpData.flags.data = 0;
    b.fpData.fp = NULL;

    return b;
}


char *fgetsClean(char *dest, int n, FILE *fp) {
    if(fgets(dest, n, fp) == NULL) return NULL;
    size_t len = strlen(dest);
    
    // Get rid of the new line
    if(dest[len - 1] == '\n') dest[len - 1] = '\0';

    // Clean the stdin
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
        case ERROR_FILE:
            printf("cannot access '%s': %s", va_arg(arg, const char *), strerror(errno));
            break;

        case ERROR_INPUT:
            puts("there was a problem trying to read the stdin");
            break;

        case ERROR_MALLOC:
            printf("problem allocating: %s", strerror(errno));
            break;
    }

    va_end(arg);

    return 1;
}