#define _GNU_SOURCE

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"
#include "ninstall.h"

void commandHelp(void) {
    puts("Ninstall, a command to keep track of installed programs.");
    putchar('\n');

    puts("USAGE:");
    puts("\tninstall <options> [file ...]");
    putchar('\n');

    puts("OPTIONS:");
    puts("\t-h, --help:\tPrints help info");
    puts("\t-n, --new:\t(Predetermined option) Adds a new program");
    puts("\t-e, --edit:\tAdds or edits a program without executing the installation commands");
    puts("\t-l, --list:\tLists all the programs in the ninstall folder");

    printf("FILE:\t Enter only the name and automatically gets converted into a '%s'\n", FILE_TYPE);
}

void commandNew(const char *program) {
    // This process is to have the path
    // Concatenates the folder, file name, and file type
    char filePath[PATH_MAX] = PRED_PATH;
    strcat(filePath, program);
    strcat(filePath, FILE_TYPE);

    FILE *fpNew;
    if((fpNew = fopen(filePath, "w+")) == NULL)
        errorHandler(ERROR_NEW_FILE);

    // Prints the comments inside the file
    fprintf("%s\n\n%s\n", INSTALL_LINE, UNINSTALL_LINE);

    // Execute nano command in the shell
    char nanoFile[PATH_MAX + 5] = "nano ";
    strcat(nanoFile, filePath);
    system(nanoFile);

    // Creates a buffer to contain the command
    char *command;
    size_t commandSize = PATH_MAX;
    if((command) = (char *)malloc(commandSize * sizeof(char)) == NULL)
        errorHandler(ERROR_MEMORY);

    // Skip the INSTALL_LINE to get to the commands
    fseek(fpNew, strlen(INSTALL_LINE), SEEK_SET);

    uint8_t boolCommandEnd = 0;
    uint8_t loopLimit = 0;
    // Execute the commands line per line
    while(!boolCommandEnd && loopLimit != LOOP_INSTALL) {
        // Read a line/command
        command = getline(&command, &commandSize, fpNew);

        // Activates the flag if the end of the command was found
        if(!strcmp(command, UNINSTALL_LINE)) boolCommandEnd = 1;

        // Executes the command if it isn't a '\n'
        if(strcmp(command, "\n")) system(command);
    }

    fclose(fpNew);
}