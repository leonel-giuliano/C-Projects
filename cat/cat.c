#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "cat.h"


int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN && argc > ARGC_MAX) errorHandler(ERROR_ARG);

    FILE *fp = NULL;
    if((fp = fopen(argv[IX_ARGV_FILE], "r")) == NULL)
        errorHandler(ERROR_FILE, argv[IX_ARGV_FILE]);

    fclose(fp);
}


void errorHandler(error_t error, ...) {
    va_list arg;
    va_start(arg, error);

    printf("cat: ");

    switch(error) {
        case ERROR_ARG:
            puts("Bad usage of the function.");
            break;

        case ERROR_FILE:
            // Print file name
            printf("%s: ", va_arg(arg, char **));
            puts("No such file or directory.");
            break;

        default:
            perror("Unkown error.");
            break;
    }

    va_end(arg);
    exit(EXIT_FAILURE);
}