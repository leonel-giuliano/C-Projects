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
    if(argc < ARGC_NEW_MIN - offset || argc > ARGC_NEW_MAX - offset) flags->BAD_USAGE = 1;

    // Check if the path is correctly written ("" or '')
    const char path[] = argv[IX_SC_CODE - offset];
    size_t pathLength = strlen(path);
    if(
        (path[0] != '"' || path[pathLength] != '"')
            &&
        (path[0] != '\'' || path[pathLength] != '\'')
    ) flags->BAD_USAGE = 1;
}

void checkRemove(int argc, char *argv[], flags_t *flags) {
    // Usage:
    // comm --remove alias

    if(argc < ARGC_REMOVE_MIN || argc > ARGC_REMOVE_MAX) flags->BAD_USAGE = 1;
}

void checkList(int argc, char *argv[], flags_t *flags) {
    // Usage:
    // comm --list

    if(argc < ARGC_LIST_MIN || argc > ARGC_LIST_MAX) flags->BAD_USAGE = 1;
}


// Subcommands
void subcommHelp(subcommIx_t subcomm) {
    // Function that is executed depending on the subcommand
    void (*helpSubcomm[])(void) = {
        helpPred,
        helpNew,
        helpRemove,
        helpList
    };
}


// Functions inside the subcommands
void helpPred(void) {
    puts("New-alias is a command to manage the personal alias in an easier way.\n");    

    puts("USAGE:");
    printf("\t%s <subcommand> [alias] [code]\n\n", COMM);

    puts("SUBCOMMANDS:");
    printf("\t%s, %s:\tPrints the information about the command\n", SUBCOMM_HELP1, SUBCOMM_HELP2);
    printf("\t%s, %s:\t(Pred. subcommand) Adds a new alias\n", SUBCOMM_NEW1, SUBCOMM_NEW2);
    printf("\t%s, %s:\tRemoves an existing alias\n", SUBCOMM_REMOVE1, SUBCOMM_REMOVE2);
    printf("\t%s, %s:\tLists all personal alias\n", SUBCOMM_LIST1, SUBCOMM_LIST2);
    putchar('\n');

    puts("ALIAS:\tIs just the name of the alias\n");

    puts("CODE:");
    puts("\tThis is only used when adding a new alias");
    puts("\tIs needed the whole path ('/home/usr/...') and it has to be written down with \" if it's a static link or with ' if it's a dynamic link\n");
}

void helpNew(void) {
    puts("USAGE:");
    printf("\t%s %s [alias] [code]\n\n", COMM, SUBCOMM_NEW2);

    puts("DESCRIPTION:");
    puts("\tCreates a new alias after giving it a path or a command");

    puts("CODE:");
    puts("\tIs needed the whole path ('/home/usr/...') and it has to be written down with \" if it's a static link or with ' if it's a dynamic link\n");

    puts("EXAMPLE:");
    printf("\t%s %s desk \"/home/usr/Desktop\"", COMM, SUBCOMM_NEW2);
}

void helpRemove(void) {
    puts("USAGE:");
    printf("\t%s %s [alias]\n\n", COMM, SUBCOMM_REMOVE2);

    puts("DESCRIPTION:");
    puts("\tRemoves a given alias\n");

    puts("EXAMPLE:");
    printf("\t%s %s desk", COMM, SUBCOMM_REMOVE2);
}

void helpList(void) {
    puts("USAGE:");
    printf("\t%s %s\n\n", COMM, SUBCOMM_LIST2);

    puts("DESCRIPTION:");
    puts("\tPrints all the personal alias\n");

    puts("EXAMPLE:");
    printf("\t%s %s\n\n", COMM, SUBCOMM_LIST2);
    puts("\tOUTPUT:");
    puts("\tdesk=\"/home/usr/Desktop\"");
    puts("\topen-desk='cd \"/home/usr/Desktop\"");
}