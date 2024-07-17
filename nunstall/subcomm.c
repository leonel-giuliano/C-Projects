#include <stdio.h>
#include <string.h>

#include "subcomm.h"
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

void subcommHelp(const char *subcommand) {
    // The 'help' function depends in the 'subcommand'
    void (*help)(void) = helpPred;

    if(CMP_SUBCOMM_REMOVE(subcommand)) help = helpRemove;

    help();
}

void subcommRemove(const char *program, const char *option) {

}