#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nunstall.h"
#include "subcomm.h"
#include "option.h"

int main(int argc, char *argv[]) {
    if(argc < ARGC_MIN || argc > ARG_MAX) errorHandler(ERROR_ARG);

    return 0;    
}

arg_t checkArg(const char *arg) {
    arg_t res = IS_FILE;

    // Checks every option
    if(!strcmp(arg, HELP_SUBCOMM1) || !strcmp(arg, HELP_SUBCOMM2))
        res = IS_SUBCOMM_HELP;
    else if(!strcmp(arg, YES_OPTION1) || !strcmp(arg, YES_OPTION2))
        res = IS_OPTION_YES;
    else if(!strcmp(arg, NO_OPTION1) || !strcmp(arg, NO_OPTION2))
        res = IS_OPTION_NO;

    return res;
}

void errorHandler(errorEvent_t error) {
    printf("ERROR: ");

    switch(error) {
        case ERROR_ARG:
            puts("Bad usage of the command.\n");
            subcommHelp();
            break;

        default:
            puts("[DEBUG] unkown error.");
            break;
    }

    exit(EXIT_FAILURE);
}