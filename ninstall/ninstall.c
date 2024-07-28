#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ninstall.h"
#include "subcommands.h"

int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARGC_MAX) errorHandler(ERROR_ARG);

    // Number that indicates the command
    subcommSelected_t subcommSelected = checkArg(argv[ARGV_SUBCOMM_OR_FILE]);

    // Subcommand depending on the parameter called
    switch(subcommSelected) {
        case HELP_SELECTED:
            subcommHelp();
            break;

        case NONE_SELECTED:
            subcommNew(argv[ARGV_SUBCOMM_OR_FILE]);
            break;

        case NEW_SELECTED:
            subcommNew(argv[ARGV_FILE]);
            break;

        case EDIT_SELECTED:
            subcommEdit(argv[ARGV_FILE]);
            break;

        case LIST_SELECTED:
            subcommList();
            break;

        default:
            errorHandler(ERROR_CALL);
            break;
    }

    return 0;
}

subcommSelected_t checkArg(char *subcomm) {
    subcommSelected_t result = NONE_SELECTED;

    // Checks if there is a subcommand
    if(!strcmp(subcomm, HELP_SUBCOMM1) || !strcmp(subcomm, HELP_SUBCOMM2))
        result = HELP_SELECTED;
    else if(!strcmp(subcomm, NEW_SUBCOMM1) || !strcmp(subcomm, NEW_SUBCOMM2))
        result = NEW_SELECTED;
    else if(!strcmp(subcomm, EDIT_SUBCOMM1) || !strcmp(subcomm, EDIT_SUBCOMM2))
        result = EDIT_SELECTED;
    else if(!strcmp(subcomm, LIST_SUBCOMM1) || !strcmp(subcomm, LIST_SUBCOMM2))
        result = LIST_SELECTED;

    // Returns "NONE_SELECTED" if it didn't enter any if statement
    return result;
}

void errorHandler(errorEvent_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            printf("The program wasn't called in the right way.\n\n");
            subcommHelp();
            break;

        case ERROR_CALL:
            puts("[DEBUG] problem with the subcomm selected.");
            break;

        case ERROR_NEW_FILE:
            puts("There was a problem creating the file.");
            break;

        case ERROR_DIR:
            puts("There was a problem trying to read the list.");
            break;

        case ERROR_MEMORY:
            puts("There was a problem allocating memory.");
            break;
    }

    exit(EXIT_FAILURE);
}