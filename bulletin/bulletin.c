#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

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


uint8_t errorHandler(errorEvent_t error, ...) {
    va_list arg;
    va_start(arg, error);

    printf("bulletin: ");

    va_end(arg);

    return 1;
}