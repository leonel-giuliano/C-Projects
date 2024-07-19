#include <stdio.h>
#include <string.h>

#include "subcomm.h"
#include "new-alias.h"

const char *subcommArray[AMOUNT_SUBCOMM][SAME_SUBCOMM] = {
    { SUBCOMM_HELP1, SUBCOMM_HELP2 },
    { SUBCOMM_NEW1, SUBCOMM_NEW2 },
    { SUBCOMM_REMOVE1, SUBCOMM_REMOVE2 },
    { SUBCOMM_LIST1, SUBCOMM_LIST2 }
};


// Check usage per subcommand
void checkNew(int argc, char *argv[], flags_t *flags) {
    // Usage:
    // comm alias "path"
    // comm --new alias 'path'

    // It determines the offset of the arguments in the case
    // that it was called without subcommand
    uint8_t offset = (!flags->HAS_SUBCOMM && IX_SUBCOMM_PRED == IX_SUBCOMM_NEW) ? 1 : 0;

    // In a case like: comm example "/home/" q
    if(argc > ARGC_NEW_MIN - offset) flags->BAD_USAGE = 1;

    // Check if the path is correctly written ("" or '')
    const char path[] = argv[IX_SC_PATH - offset];
    size_t pathLength = strlen(path);
    if(
        (path[0] != '"' || path[pathLength] != '"')
            &&
        (path[0] != '\'' || path[pathLength] != '\'')
    ) flags->BAD_USAGE = 1;
}

void checkRemove(int argc, char *argv[], flags_t *flags) {

}

void checkList(int argc, char *argv[], flags_t *flags) {

}


// Functions inside the subcommands
void helpPred(void) {
    puts("New-alias is a command to manage the personal alias in an easier way.\n");    

    puts("USAGE:");
    printf("\t%s <subcommand> [alias] [path]\n\n", COMM);

    puts("SUBCOMMANDS:");
    printf("\t%s, %s:\tPrints the information about the command\n", SUBCOMM_HELP1, SUBCOMM_HELP2);
    printf("\t%s, %s:\t(Pred. subcommand) Adds a new alias\n", SUBCOMM_NEW1, SUBCOMM_NEW2);
    printf("\t%s, %s:\tRemoves an existing alias\n", SUBCOMM_REMOVE1, SUBCOMM_REMOVE2);
    printf("\t%s, %s:\tLists all personal alias\n", SUBCOMM_LIST1, SUBCOMM_LIST2);
    putchar('\n');

    puts("ALIAS:\tIs just the name of the alias\n");

    puts("PATH:");
    puts("\tThis is only used when adding a new alias");
    puts("\tIs needed the whole path ('/home/usr/...') and it has to be written down with \" if it's a static link or with ' if it's a dynamic link");
}