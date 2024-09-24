#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

#include "bulletin.h"
#include "student.h"
#include "file.h"


int main() {
    bulletin_t bulletin = initBt();

    return 0;
}


bulletin_t initBt() {
    bulletin_t b;

    b.markNameList = NULL;
    b.students = NULL;
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

    va_end(arg);

    return 1;
}