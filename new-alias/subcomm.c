#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "subcomm.h"
#include "new-alias.h"

const char *subcommArray[AMOUNT_SUBCOMM][SAME_SUBCOMM] = {
    { SUBCOMM_HELP1, SUBCOMM_HELP2 },
    { SUBCOMM_NEW1, SUBCOMM_NEW2 },
    { SUBCOMM_EDIT1, SUBCOMM_EDIT2 },
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

    // Check if the path is correctly written if it is a dynamic link
    const char *path = argv[IX_SC_CODE - offset];
    size_t pathLength = strlen(path);

    if(
        (path[0] == '\'' && path[pathLength] != '\'')
            ||
        (path[0] != '\'' && path[pathLength] == '\'')
    ) flags->BAD_USAGE = 1;
}

void checkEdit(int argc, char *argv[], flags_t *flags) {
    // Usage:
    // comm --edit alias

    if(argc < ARGC_EDIT_MIN || argc > ARGC_EDIT_MAX) flags->BAD_USAGE = 1;

    (void)argv;
}

void checkRemove(int argc, char *argv[], flags_t *flags) {
    // Usage:
    // comm --remove alias

    if(argc < ARGC_REMOVE_MIN || argc > ARGC_REMOVE_MAX) flags->BAD_USAGE = 1;

    (void)argv;
}

void checkList(int argc, char *argv[], flags_t *flags) {
    // Usage:
    // comm --list

    if(argc < ARGC_LIST_MIN || argc > ARGC_LIST_MAX) flags->BAD_USAGE = 1;

    (void)argv;
}


// Subcommands
void subcommPred(char *argv[]) {
    subcommNew(argv[IX_ALIAS], argv[IX_CODE]);
}

void subcommHelp(subcommIx_t subcomm, flags_t flags) {
    // Determinates the function to execute
    subcommIx_t ix = subcomm;

    // Function that is executed depending on the subcommand
    void (*helpSubcomm[])(void) = {
        helpPred,
        helpNew,
        helpEdit,
        helpRemove,
        helpList
    };

    // In case it didn't found another subcommand
    if(!flags.HAS_SUBCOMM) ix = IX_SUBCOMM_HELP;

    helpSubcomm[ix]();
}

void subcommNew(const char *alias, const char *code) {
    // Get the path of the bash to edit
    char bashPath[PATH_MAX] = "";
    strcat(bashPath, getenv("HOME"));
    strcat(bashPath, BASH_FILE);

    // Opens the bash only to read because the way of editing
    // the file in between lines makes a copy of the bash needed
    FILE *fpBash = NULL;
    if((fpBash = fopen(bashPath, "r")) == NULL)
        errorHandler(ERROR_OPEN_BASH);

    // Get the path for the temporal
    char tempPath[PATH_MAX] = "";
    strcat(tempPath, getenv("HOME"));
    strcat(tempPath, BASH_TEMP);

    // Creates a temporal file in order to add the alias and
    // keeping all the other info
    FILE *fpTemp = NULL;
    if((fpTemp = fopen(tempPath, "w")) == NULL) {
        fclose(fpBash);

        errorHandler(ERROR_BASH_TEMP);
    }

    // Reads line per line to search for the ALIAS_COMMENT
    // Also, copies every line in the temporal file
    char *line = NULL;
    size_t lineLength = LINE_MAX;
    if((line = (char *)malloc(lineLength * sizeof(char))) == NULL) {
        fclose(fpBash);
        fclose(fpTemp);

        errorHandler(ERROR_MEMORY);
    }

    size_t loopBash = 0;
    do {
        loopBash++;

        getline(&line, &lineLength, fpBash);

        // Check if the end of the file was reached to avoid
        // printing the line twice inside the temporal
        if(feof(fpBash)) break;

        fputs(line, fpTemp);
    } while(strcmp(line, ALIAS_COMMENT) && loopBash != LOOP_BASH);

    // [DEBUG]: add a function to add the alias comment if it wasn't found

    // Add the alias
    fprintf(fpTemp, "alias %s=\"%s\"\n", alias, code);

    // Copies the next lines from the bash
    loopBash = 0;
    do {
        loopBash++;

        getline(&line, &lineLength, fpBash);

        // Check if the end of the file was reached to avoid
        // printing the line twice inside the temporal
        if(feof(fpBash)) break;

        fputs(line, fpTemp);
    } while(loopBash != LOOP_BASH);

    fclose(fpBash);
    fclose(fpTemp);

    // Make the temporal file the bash file
    remove(bashPath);
    rename(tempPath, bashPath);
}


// Functions inside the subcommands
void helpPred(void) {
    puts("New-alias is a command to manage the personal alias in an easier way.\n");    

    puts("USAGE:");
    printf("\t%s <subcommand> [alias] [code]\n\n", COMM);

    puts("SUBCOMMANDS:");
    printf("\t%s, %s:\tPrints the information about the command\n", SUBCOMM_HELP1, SUBCOMM_HELP2);
    printf("\t%s, %s:\t(Pred. subcommand) Adds a new alias\n", SUBCOMM_NEW1, SUBCOMM_NEW2);
    printf("\t%s, %s:\tEdits the code of an already existing alias\n", SUBCOMM_EDIT1, SUBCOMM_EDIT2);
    printf("\t%s, %s:\tRemoves an existing alias\n", SUBCOMM_REMOVE1, SUBCOMM_REMOVE2);
    printf("\t%s, %s:\tLists all personal alias\n", SUBCOMM_LIST1, SUBCOMM_LIST2);
    putchar('\n');

    puts("ALIAS:\tIs just the name of the alias\n");

    puts("CODE:");
    puts("\tThis is only used when adding a new alias");
    puts("\tIt can be either a command or a path");
    puts("\tIf it's a command, with the '' would be enough, but the path is a static one (\"\") if written without quotes or a dynamic one if written with ''");
}

void helpNew(void) {
    puts("USAGE:");
    printf("\t%s %s [alias] [code]\n\n", COMM, SUBCOMM_NEW2);

    puts("DESCRIPTION:");
    puts("\tCreates a new alias after giving it a path or a command");

    puts("CODE:");
    puts("\tIt can be either a command or a path");
    puts("\tIf it's a command, with the '' would be enough, but the path is a static one (\"\") if written without quotes or a dynamic one if written with ''\n");

    puts("EXAMPLE:");
    printf("\t%s %s desk \"/home/usr/Desktop\"\n", COMM, SUBCOMM_NEW2);
}

void helpEdit(void) {
    puts("USAGE:");
    printf("\t%s %s [alias] [code]\n\n", COMM, SUBCOMM_EDIT2);

    puts("DESCRIPTION:");
    puts("\tEdits the code or path of an already existing alias");
    puts("\tIt gives back an error message in the case the alias wasn't found\n");    

    puts("CODE:");
    puts("\tIt can be either a command or a path");
    puts("\tIf it's a command, with the '' would be enough, but the path is a static one (\"\") if written without quotes or a dynamic one if written with ''\n");

    puts("EXAMPLE:");
    printf("\t%s %s desk \"/home/usr/Desktop/desk\"\n", COMM, SUBCOMM_EDIT2);
}

void helpRemove(void) {
    puts("USAGE:");
    printf("\t%s %s [alias]\n\n", COMM, SUBCOMM_REMOVE2);

    puts("DESCRIPTION:");
    puts("\tRemoves a given alias\n");
    puts("\tIt gives back an error message in the case the alias wasn't found\n");    

    puts("EXAMPLE:");
    printf("\t%s %s desk\n", COMM, SUBCOMM_REMOVE2);
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