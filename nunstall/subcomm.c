#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
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

uint8_t checkRemove(int argc, char *argv[]) {
    // Offset in case it was called without subcommand
    uint8_t offset = (CMP_SUBCOMM(argv[IX_SUBCOMM], IX_SUBCOMM_REMOVE)) ? 0 : 1;

    // Mostly in case of sth like: nunstall firefox -y -n
    if(argc > ARGC_MAX - offset) errorHandler(ERROR_ARG);

    // Checks if there is an option
    uint8_t boolOption = 0;
    // Checks if the command was called correctly
    for(uint8_t i = 0; i < AMOUNT_OPTION; i++) {
        // If there is an option where the file is supposed to be
        if(CMP_OPTION(argv[IX_SC_FILE - offset], i))
            errorHandler(ERROR_ARG);

        // Checks if there if the option is okay in the
        // case that it was passed
        if(argc == ARGC_MAX - offset && (CMP_OPTION(argv[IX_SC_OPTION - offset], i)))
            boolOption = 1;
    }

    // In case there were more parameters that weren't a valid option
    if(argc == ARGC_MAX - offset && !boolOption)
        errorHandler(ERROR_ARG);
    // Ex: nunstall --remove firefox -a

    return offset;
}

void getDir(char *argv[], uint8_t offset, char *dirPath) {
    // Get the directory of the ninstall folder
    strcpy(dirPath, getenv("HOME"));
    strcat(dirPath, PATH_IN_HOME);

    DIR *dirFolder;
    if((dirFolder = opendir(dirPath)) == NULL)
        errorHandler(ERROR_DIR);

    // Create the struct of the file data
    struct dirent *dirFile;
    const char *program = argv[IX_SC_FILE - offset];

    // Iterate through every file inside of it
    uint8_t boolProgram = 0;
    int loopFile = 0;
    while(!boolProgram && (dirFile = readdir(dirFolder)) != NULL && loopFile != LOOP_FILE) {
        loopFile++;

        // Skip the '.' and '..'
        if(!strcmp(dirFile->d_name, ".") || !strcmp(dirFile->d_name, ".."))
            continue;

        // The "+ 1" is to ignore the '\0'
        size_t length = strlen(dirFile->d_name) - TYPE_LENGTH + 1;
        // Compare the file name withouth the extension
        if(!strncmp(dirFile->d_name, program, length))
            boolProgram = 1;
    }

    // In case the program wasn't found
    if(!boolProgram) errorHandler(ERROR_PROGRAM_NOT_FOUND);

    // Save the file path
    strcat(dirPath, dirFile->d_name);

    closedir(dirFolder);
}

void subcommRemove(int argc, char *argv[]) {
    // Offset in case it was called without subcommand
    // This process makes sure the command is correctly passed
    uint8_t offset = checkRemove(argc, argv);
    char filePath[PATH_MAX] = "";
    getDir(argv, offset, filePath);

    // Open the file
    FILE *fpProgram;
    if((fpProgram = fopen(filePath, "r")) == NULL)
        errorHandler(ERROR_FILE);

    // Create str to save the command lines
    char *command;
    size_t commandSize = PATH_MAX;
    if((command = (char *)malloc(commandSize * sizeof(char))) == NULL)
        errorHandler(ERROR_MEMORY);

    // Read first line of the file
    getline(&command, &commandSize, fpProgram);
    // Skip until the uninstallation commands are found
    size_t loopComm = 0;
    while(strcmp(command, UNINSTALL_LINE_N) && loopComm != LOOP_COMM) {
        loopComm++;
        // Read one line
        getline(&command, &commandSize, fpProgram);

        // If the file didn't contain the uninstallation
        // comment, break the iteration and exit the code
        if(feof(fpProgram)) break;
    }

    // In case the file didn't had uninstall commands
    if(feof(fpProgram)) {
        puts("There wasn't any uninstallation commands.");

        free(command);
        fclose(fpProgram);

        return;
    }

    puts("UNINSTALLING:\n");

    // Execute every command
    loopComm = 0;
    while(loopComm != LOOP_COMM) {
        loopComm++;

        getline(&command, &commandSize, fpProgram);

        // If it reaches the end of the file, the command
        // gets executed twice, this fixes that
        if(feof(fpProgram)) break;

        // Execute command
        printf("Executing command: %s", command);
        system(command);
        putchar('\n');
    }

    free(command);
    fclose(fpProgram);
}