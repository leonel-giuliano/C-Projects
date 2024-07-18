#define _GNU_SOURCE

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "subcommands.h"
#include "ninstall.h"

FILE *manageFile(const char *program, const char *mode) {
    // This process is to have the path
    // Concatenates the home folder, the folder, file name, and file type
    char filePath[PATH_MAX] = "";
    // Gets the home folder
    strcat(filePath, getenv("HOME"));
    strcat(filePath, PATH_IN_HOME);
    strcat(filePath, program);
    strcat(filePath, FILE_TYPE);

    FILE *fp;
    if((fp = fopen(filePath, mode)) == NULL)
        errorHandler(ERROR_NEW_FILE);

    // Prints the comments inside the file
    // This only happens in subcommNew
    if(!strcmp(mode, "w+")) {
        fprintf(fp, "%s\n\n%s\n", INSTALL_LINE, UNINSTALL_LINE);
        fflush(fp);
    }

    // Execute nano command in the shell
    char nanoFile[PATH_MAX + 5] = "nano ";
    strcat(nanoFile, filePath);
    system(nanoFile);

    return fp;
}

void subcommHelp(void) {
    puts("Ninstall, a command to keep track of installed programs.");
    putchar('\n');

    puts("USAGE:");
    puts("\tninstall <subcommands> [file ...]");
    putchar('\n');

    puts("SUBCOMMANDS:");
    puts("\t-h, --help:\tPrints help info");
    puts("\t-n, --new:\t(Predetermined subcommand) Adds a new program");
    puts("\t-e, --edit:\tAdds or edits a program without executing the installation commands");
    puts("\t-l, --list:\tLists all the programs in the ninstall folder");
    putchar('\n');

    printf("FILE:\t Enter only the name and automatically gets converted into a '%s'\n", FILE_TYPE);
}

void subcommNew(const char *program) {
    FILE *fpNew = manageFile(program, "w+");

    // Creates a buffer to contain the command
    char *command;
    size_t commandSize = PATH_MAX;
    if((command = (char *)malloc(commandSize * sizeof(char))) == NULL)
        errorHandler(ERROR_MEMORY);

    // Skip the INSTALL_LINE to get to the commands
    fseek(fpNew, INSTALL_LENGTH + 1, SEEK_SET);
    // "+ 1" for the '\n'

    uint8_t boolCommandEnd = 0;
    int loopLimit = 0;
    // Execute the commands line per line
    puts("INSTALATION:\n");
    while(!boolCommandEnd && loopLimit != LOOP_INSTALL) {
        // Prevents the loop to go for ever
        loopLimit++;

        // Read a line/command
        getline(&command, &commandSize, fpNew);

        // Activates the flag if the end of the command was found
        char endLine[UNINSTALL_LENGTH + 1] = UNINSTALL_LINE;
        // The "+ 1" is for the '\n'
        strcat(endLine, "\n");

        if(!strcmp(command, endLine)) boolCommandEnd = 1;

        // Executes the command if it isn't a '\n'
        if(!boolCommandEnd && strcmp(command, "\n")) {
            printf("Executing: %s", command);
            system(command);
        }
    }

    putchar('\n');
    printf("The file %s%s was created and installed successfully.\n", program, FILE_TYPE);

    free(command);
    fclose(fpNew);
}

void subcommEdit(const char *program) {
    FILE *fpEdit = manageFile(program, "r");
    printf("The file %s%s was edited successfully.\n", program, FILE_TYPE);

    fclose(fpEdit);
}

void subcommList(void) {
    // This process is to have the path
    // Concatenates the home folder and the folder
    char dirPath[PATH_MAX] = "";
    // Gets the home folder
    strcat(dirPath, getenv("HOME"));
    strcat(dirPath, PATH_IN_HOME);

    DIR *dirList;
    if((dirList = opendir(dirPath)) == NULL)
        errorHandler(ERROR_DIR);

    // Read every file name
    struct dirent *dirFile;
    int loopList = 0;
    while((dirFile = readdir(dirList)) != NULL && loopList != LOOP_LIST) {
        loopList++;
        // Makes sure to exclude the './' and '../'
        if(strcmp(dirFile->d_name, ".") && strcmp(dirFile->d_name, "..")) {
            size_t length = strlen(dirFile->d_name);

            // Prints individually every char in
            // order not to print the FILE_TYPE
            for(uint8_t i = 0; i < length - TYPE_LENGTH + 1; i++)
                putchar(dirFile->d_name[i]);
            // The "- 1" is for the '\0'

            putchar('\n');
        }
    }

    closedir(dirList);
}