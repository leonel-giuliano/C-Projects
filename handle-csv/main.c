#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "error.h"

int main(int argc, char *argv[]) {
    if(argc != ARGC_PARAM) errorHandler(ERROR_ARGC);
    // Error in case wrong called program

    FILE *fpData;
    if((fpData = fopen(argv[ARGV_FILE], "a+")) == NULL)
        errorHandler(ERROR_FILE);
}