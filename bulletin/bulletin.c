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
    bulletin_t bulettin;
    // Try to open the file if it exists
    if((bulettin.file = fopen(getDir(bulettin.pathStr), "r+")) == NULL) {
        if((bulettin.file = fopen(getDir(bulettin.pathStr), "w+")) == NULL)
            errorHandler(ERROR_FILE, bulettin.pathStr);
    }

    close_file:
        fclose(bulettin.file);

        return 0;
}


void errorHandler(errorEvent_t error, ...) {
    va_list arg;
    va_start(arg, error);

    printf("bulletin: ");

    switch(error) {
        case ERROR_FILE:
            printf("cannot access '%s': %s", va_arg(arg, const char *), strerror(errno));
            break;
    }

    va_end(arg);

    exit(EXIT_FAILURE);
}