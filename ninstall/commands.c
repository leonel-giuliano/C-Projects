#include <stdio.h>
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

    fclose(fpNew);
}