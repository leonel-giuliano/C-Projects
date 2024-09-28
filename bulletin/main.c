#include <stdio.h>
#include <errno.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

#include "main.h"


char *fgetsClean(char *str, int n, FILE *fp) {
    if(fgets(str, n, fp) == NULL) return NULL;
    size_t len = strlen(str);

    // If there wasn't overflowing data, get rid of the '\n'
    if(str[len - 1] == '\n') str[len - 1] = '\0';
    // Clean the stdin
    else if(fp == stdin) {
        char ch;
        while((ch = getchar()) != '\n' && ch != EOF);
    }

    return str;
}


uint8_t errorHandler(errorEvent_t error, ...) {
    va_list arg;
    va_start(arg, error);

    printf("bulletin: ");

    switch(error) {
        case ERROR_FILE:
            printf("cannot access '%s': %s\n", va_arg(arg, const char *), strerror(errno));
            break;

        case ERROR_NOMEM:
            printf("problem allocating: %s\n", strerror(errno));
            break;

        case ERROR_READ_FILE:
            puts("there was a problem reading the file");
            break;

        case ERROR_INPUT:
            puts("problem reading the input");
            break;
    }

    va_end(arg);

    return 1;
}
