#include <stdio.h>
#include <errno.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

#include "main.h"


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
    }

    va_end(arg);

    return 1;
}
