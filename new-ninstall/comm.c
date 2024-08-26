#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>

#include "detect-args.h"

#include "comm.h"
#include "ninstall.h"


// Commands

void helpComm(op_t op) {
    switch(op) {
        case OP_PRED:
            helpPred();
            break;

        case OP_NEW:
            helpNew();
            break;

        case OP_EDIT:
            helpEdit();
            break;

        case OP_LIST:
            helpList();
            break;
    }
}

void newComm(const char *program) {
    char programPath[PATH_MAX];
    getProgramPath(programPath, program);

    // Creates the file for the program (or erases the content of the file)
    FILE *fpProgram = NULL;
    if(fpProgram = fopen(programPath, "w+"));

    fputs("# Installation\n\n", fpProgram);
    fputs("# Uninstallation", fpProgram);

    // Use the command nano for the file
    char nano[PATH_MAX + NANO_LEN];
    strcpy(nano, "nano ");
    strcat(nano, programPath);
    system(nano);

    fclose(fpProgram);
}


// Inside functions

void printBold(const char *str) {
    printf("%s%s%s", BOLD_ON, str, BOLD_OFF);
}

void getProgramPath(char *path, const char *program) {
    char *home = getenv("HOME");

    // In case the enviroment couldn't be passed
    if(home == NULL) errorHandler(ERROR_HOME);

    // Save the ninstall folder path
    strncpy(path, home, PATH_MAX - 1);
    path[PATH_MAX - 1] = '\0';

    size_t pathLen = strlen(path);
    strncat(path, "/ninstall/", PATH_MAX - pathLen - 1);

    pathLen = strlen(path);
    strncat(path, program, PATH_MAX - pathLen - 1);

    pathLen = strlen(path);
    strncat(path, ".list", PATH_MAX - pathLen - 1);
}


// Check Functions

void checkNew(int argc, argOperation_t argOp[]) {
    // Check the amount of arguments
    if(argc < ARG_NEW_MIN || argc > ARG_NEW_MAX) bad_usage = 1;

    // Checks if other operations where passed
    else {
        for(uint8_t i = IX_COMM + 1; i < argc; i++) {
            // The "- 1" is bc of the script command
            if(argOp[i].type != NO_OPERATION) bad_usage = 1;
        }
    }
}

void checkEdit(int argc, argOperation_t argOp[]) {
    // Check the amount of arguments
    if(argc < ARG_EDIT_MIN || argc > ARG_EDIT_MAX) bad_usage = 1;

    // Checks if other operations where passed
    else {
        for(uint8_t i = IX_COMM + 1; i < argc; i++) {
            // The "- 1" is bc of the script command
            if(argOp[i].type != NO_OPERATION) bad_usage = 1;
        }
    }
}

void checkList(int argc, argOperation_t argOp[]) {
    // Check the amount of arguments
    if(argc < ARG_LIST_MIN || argc > ARG_LIST_MAX) bad_usage = 1;

    (void)argOp;
}


// Help functions

void helpPred() {
    puts("Ninstall is a script that keeps track of the installed applications by the user.\n");

    printBold("USAGE:\n");
    puts("\tninstall [command] (...program)\n");

    printBold("OPTION:\n");
    puts("\t-h,--help: Prints a detailed explanation of the script or command used.\n");

    printBold("COMMAND:\n");
    puts("\tnew: (Pred. command) Creates a file in the ninstall folder with the name of the program and then it executes the installation command lines.");
    puts("\tedit: Edit the command lines of a program or creates a file without executing the installation command lines.");
    puts("\tlist: Prints all the program names.\n");
}

void helpNew() {
    printBold("USAGE:\n");
    puts("\tninstall new (...program)\n");

    puts("Creates a file in the ninstall folder with the name of the program and then it executes the installation command lines.\n");

    printBold("EXAMPLE:\n");
    puts("\tninstall new firefox\n");
    puts("\tThis creates a file called 'firefox.list' inside the ninstall folder that can be then changed with 'edit', be printed with 'list' or deleted with the script 'nunstall'.\n");
}

void helpEdit() {
    printBold("USAGE:\n");
    puts("\tninstall edit (...program)\n");

    puts("Edit the command lines of a program or creates a file without executing the installation command lines.\n");

    printBold("EXAMPLE:\n");
    puts("\tninstall edit firefox\n");
    puts("\tThis searches for the file 'firefox.list' and lets you edit the content.");
    puts("\tIn case it wasn't file, it creates it and doesn't execute the installation commands.\n");
}

void helpList() {
    printBold("USAGE:\n");
    puts("\tninstall list\n");

    puts("Prints all the program names, that would be all the '.list' files inside the ninstall folder.\n");

    printBold("EXAMPLE:\n");
    puts("\tninstall list\n");
    puts("OUTPUT:");
    puts("\tfirefox");
    puts("\tdiscord");
    puts("\tflatseal\n");
}