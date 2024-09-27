#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

#include "main.h"
#include "sales.h"


int main() {
    return 0;
}

void errorHandler(errorEvent_t error, ...) {
    va_list arg;
    va_start(arg, error);

    va_end(arg);

    return 1;
}