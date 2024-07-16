#include <stdio.h>
#include <stdlib.h>

#include "ninstall.h"
#include "commands.h"

int main(int argc, char *argv[]) {
    if(argc > ARGC_MAX) errorHandler(ERROR_ARG);
}

void errorHandler(errorEvent_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            printf("The program wasn't called in the right way.\n\n");
            commandHelp();
            break;

        case ERROR_NEW_FILE:
            puts("There was a problem creating the file.");
            break;

        case ERROR_MEMORY:
            puts("There was a problem allocating memory.");
            break;
    }

    exit(EXIT_FAILURE);
}