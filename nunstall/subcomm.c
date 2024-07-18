#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "subcomm.h"
#include "nunstall.h"
#include "option.h"

const char *subcommArray[AMOUNT_SUBCOMM][SAME_SUBCOMM] = {
    { SUBCOMM_HELP1, SUBCOMM_HELP2 },
    { SUBCOMM_REMOVE1, SUBCOMM_REMOVE2 }
};

void helpPred(void) {
    puts("Nunstall is a command to uninstall a listed program.\n");

    puts("USAGE:");
    puts("\tnunstall <subcommand> [file ...] <option>\n");

    puts("SUBCOMMANDS:");
    printf("\t%s, %s: Prints the information about the command\n", SUBCOMM_HELP1, SUBCOMM_HELP2);
    printf("\t%s, %s: (Pred. subcommand) Uninstalls the program requested\n\n", SUBCOMM_REMOVE1, SUBCOMM_REMOVE2);

    puts("OPTIONS:");
    printf("\t%s, %s: Can be used in the subcommand 'remove'. Allows to remove the program file without asking\n", OPTION_YES1, OPTION_YES2);
    printf("\t%s, %s: Can be used in the subcommand 'remove'. Prevents from removing the program file without asking\n\n", OPTION_NO1, OPTION_NO2);
}

void helpRemove(void) {
    puts("USAGE:");
    printf("\tninstall %s [file ...] <option>\n\n", SUBCOMM_REMOVE2);

    puts("OPTIONS:");
    printf("\t%s, %s: Allows to remove the program file without asking\n", OPTION_YES1, OPTION_YES2);
    printf("\t%s, %s: Prevents from removing the program file without asking\n\n", OPTION_NO1, OPTION_NO2);

    puts("EXAMPLES:");
    printf("\tninstall %s firefox %s\n\n", SUBCOMM_REMOVE2, OPTION_YES2);
}

void subcommHelp(int argc, char *argv[]) {
    // This is the function that is going to be executed
    // depending on the other subcommands used
    void (*help[])(void) = {
        helpPred,
        helpRemove
    };

    // Ix of the help command
    uint8_t subcomm = 0;
    // Iterate through every argument
    for(uint8_t i = IX_COMM + 1; i < argc; i++) {
        // Iterate through every subcommand
        for(uint8_t j = 0; j < AMOUNT_SUBCOMM; j++) {
            if(j == IX_SUBCOMM_HELP) continue;

            if(CMP_SUBCOMM(argv[i], j))
                // Saves the ix of the subcommand
                subcomm = j;
        }
    }

    help[subcomm]();
}

void subcommRemove(int argc, char *argv[]) {

}