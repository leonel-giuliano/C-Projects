#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "subcomm.h"
#include "new-alias.h"
#include "option.h"

const char *subcommArray[AMOUNT_SUBCOMM][SAME_SUBCOMM] = {
    { SUBCOMM_HELP1, SUBCOMM_HELP2 },
    { SUBCOMM_NEW1, SUBCOMM_NEW2 },
    { SUBCOMM_EDIT1, SUBCOMM_EDIT2 },
    { SUBCOMM_REMOVE1, SUBCOMM_REMOVE2 },
    { SUBCOMM_LIST1, SUBCOMM_LIST2 }
};


// Check usage per subcommand
void checkNew(int argc, flags_t *flags) {
    // Usage:
    // comm alias "path"
    // comm --new alias 'path'

    // It determines the offset of the arguments in the case
    // that it was called without subcommand
    uint8_t offset = (!flags->HAS_SUBCOMM && IX_SUBCOMM_PRED == IX_SUBCOMM_NEW) ? 1 : 0;

    // In a case like: comm example "/home/" q
    if(argc < ARGC_NEW_MIN - offset || argc > ARGC_NEW_MAX - offset) flags->BAD_USAGE = 1;

    // Checks if there was more arguments than needed without using options
    if(argc > ARGC_NEW_MIN - offset && !flags->HAS_OPTION) flags->BAD_USAGE = 1;
}

void checkEdit(int argc, flags_t *flags) {
    // Usage:
    // comm --edit alias

    if(argc < ARGC_EDIT_MIN || argc > ARGC_EDIT_MAX) flags->BAD_USAGE = 1;

    if(argc > ARGC_EDIT_MIN && !flags->HAS_OPTION) flags->BAD_USAGE = 1;
}

void checkRemove(int argc, flags_t *flags) {
    // Usage:
    // comm --remove alias

    if(argc < ARGC_REMOVE_MIN || argc > ARGC_REMOVE_MAX) flags->BAD_USAGE = 1;

    if(flags->HAS_OPTION) flags->BAD_USAGE = 1;
}

void checkList(int argc, flags_t *flags) {
    // Usage:
    // comm --list

    if(argc < ARGC_LIST_MIN || argc > ARGC_LIST_MAX) flags->BAD_USAGE = 1;

    if(flags->HAS_OPTION) flags->BAD_USAGE = 1;
}


// Subcommands
void subcommPred(char *argv[], optionIx_t option, flags_t flags) {
    uint8_t offset = (!flags.HAS_OPTION) ? 1 : 0;

    subcommNew(argv[IX_ALIAS], argv[IX_OP_CODE - offset], option);
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

void subcommNew(const char *alias, const char *code, optionIx_t option) {
    // Choose the quote depending on the option
    char ch = (option == IX_OPTION_STATIC) ? '"' : '\'';

    // This function basically does everything needed
    writeAlias(
        ALIAS_COMMENT,
        ALIAS_COMMENT_LENGTH,
        "alias %s=%c%s%c\n",
        alias,
        ch,
        code,
        ch
    );
}

void subcommEdit(const char *alias, const char *code, optionIx_t option) {
    // Choose the quote depending on the option
    char ch = (option == IX_OPTION_STATIC) ? '"' : '\'';

    // Allocate the string that is going to be search inside the file
    char *searchStr;
    size_t aliasLength = strlen(alias);
    if((searchStr = (char *)malloc((aliasLength + ALIAS_LENGTH) * sizeof(char))) == NULL)
        errorHandler(ERROR_MEMORY);

    // Connect the "alias " + aliasName + "="
    strcpy(searchStr, "alias ");
    strcat(searchStr, alias);
    // This is to go to the last char and the "- 1" because of \0
    searchStr[aliasLength + ALIAS_LENGTH - 1] = '=';

    // This function basically does everything needed
    writeAlias(
        searchStr,
        aliasLength + ALIAS_LENGTH - 1,
        "%c%s%c\n",
        ch,
        code,
        ch
    );
}


// Functions inside the subcommands
void helpPred(void) {
    puts("New-alias is a command to manage the personal alias in an easier way.\n");    

    puts("USAGE:");
    printf("\t%s <subcommand> [alias] <option> [code]\n\n", COMM);

    puts("SUBCOMMANDS:");
    printf("\t%s, %s:\tPrints the information about the command\n", SUBCOMM_HELP1, SUBCOMM_HELP2);
    printf("\t%s, %s:\t(Pred. subcommand) Adds a new alias\n", SUBCOMM_NEW1, SUBCOMM_NEW2);
    printf("\t%s, %s:\tEdits the code of an already existing alias\n", SUBCOMM_EDIT1, SUBCOMM_EDIT2);
    printf("\t%s, %s:\tRemoves an existing alias\n", SUBCOMM_REMOVE1, SUBCOMM_REMOVE2);
    printf("\t%s, %s:\tLists all personal alias\n", SUBCOMM_LIST1, SUBCOMM_LIST2);
    putchar('\n');

    puts("ALIAS:\tIs just the name of the alias\n");

    puts("OPTION:");
    printf("\t%s, %s:\t(Pred. option) Makes the code a static link (\"\")\n", OPTION_STATIC1, OPTION_STATIC2);
    printf("\t%s, %s:\tMakes the code a dynamic link ('')\n", OPTION_DYNAMIC1, OPTION_DYNAMIC2);
    putchar('\n');

    puts("CODE:");
    puts("\tThis is only used when adding a new alias");
    puts("\tIt can be either a command or a path");
}

void helpNew(void) {
    puts("USAGE:");
    printf("\t%s %s [alias] <option> [code]\n\n", COMM, SUBCOMM_NEW2);

    puts("DESCRIPTION:");
    puts("\tCreates a new alias after giving it a path or a command");

    puts("OPTION:");
    printf("\t%s, %s:\t(Pred. option) Makes the code a static link (\"\")\n", OPTION_STATIC1, OPTION_STATIC2);
    printf("\t%s, %s:\tMakes the code a dynamic link ('')\n", OPTION_DYNAMIC1, OPTION_DYNAMIC2);
    putchar('\n');

    puts("CODE:");
    puts("\tIt can be either a command or a path");

    puts("EXAMPLE:");
    printf("\t%s %s desk %s /home/usr/Desktop\n", COMM, SUBCOMM_NEW2, OPTION_STATIC2);
}

void helpEdit(void) {
    puts("USAGE:");
    printf("\t%s %s [alias] <option> [code]\n\n", COMM, SUBCOMM_EDIT2);

    puts("DESCRIPTION:");
    puts("\tEdits the code or path of an already existing alias");
    puts("\tIt gives back an error message in the case the alias wasn't found\n");    

    puts("OPTION:");
    printf("\t%s, %s:\t(Pred. option) Makes the code a static link (\"\")\n", OPTION_STATIC1, OPTION_STATIC2);
    printf("\t%s, %s:\tMakes the code a dynamic link ('')\n", OPTION_DYNAMIC1, OPTION_DYNAMIC2);
    putchar('\n');

    puts("CODE:");
    puts("\tIt can be either a command or a path");

    puts("EXAMPLE:");
    printf("\t%s %s desk --dynamic /home/usr/Desktop/desk", COMM, SUBCOMM_EDIT2);
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

void writeAlias(const char *searchStr, size_t nSearch, const char *print, ...) {
    // Get the path of the bash to edit
    char bashPath[PATH_MAX] = "";
    strcpy(bashPath, getenv("HOME"));
    strcat(bashPath, BASH_FILE);

    // Opens the bash only to read because the way of editing
    // the file in between lines makes a copy of the bash needed
    FILE *fpBash = NULL;
    if((fpBash = fopen(bashPath, "r")) == NULL)
        errorHandler(ERROR_OPEN_BASH);

    // Get the path for the temporal
    char tempPath[PATH_MAX] = "";
    strcpy(tempPath, getenv("HOME"));
    strcat(tempPath, BASH_TEMP);

    // Creates a temporal file in order to add the alias and
    // keeping all the other info
    FILE *fpTemp = NULL;
    if((fpTemp = fopen(tempPath, "w")) == NULL) {    // Add the alias
    // The character depends on the option chosen

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

        // In the case that it was found, exit the loop
        if(!strncmp(line, searchStr, nSearch)) break;

        fputs(line, fpTemp);
    } while(loopBash != LOOP_BASH);

    fputs(searchStr, fpTemp);

    // Get the arguments to print
    va_list(args);
    va_start(args, print);

    // Prints the text recieved
    vfprintf(fpTemp, print, args);

    va_end(args);

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