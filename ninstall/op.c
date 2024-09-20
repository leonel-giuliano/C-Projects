#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h>

#include "argop.h"

#include "ninstall.h"
#include "op.h"


FILE *fopenProgram(char *path, const char *program) {
    // Get home env for the ninstall folder
    char *home = getenv("HOME");
    if(home == NULL) return NULL;

    snprintf(path, PATH_MAX, "%s/%s/%s.list", home, NINSTALL_HOME_FOLDER, program);

    // Create file (new) or don't truncate it (edit, remove)
    return fopen(path, "a+");
}

FILE *fopenNano(const char *program) {
    char path[PATH_MAX];
    FILE *fp = fopenProgram(path, program);
    if(fp == NULL) return NULL;

    // Check if the file is empty to write the comments
    fseek(fp, 0, SEEK_END);
    if(!ftell(fp)) fprintf(fp, "%s\n%s", INSTALL_STR, UNINSTALL_STR);

    // Open the file in nano
    char nano[PATH_MAX + NANO_LEN];
    snprintf(nano, PATH_MAX + NANO_LEN, "nano %s", path);
    system(nano);

    return fp;
}


/* FLAGS */

void helpFlag() {
    PRINT_B("USAGE\n");
    puts("\tninstall [OPTION] [PROGRAM] [FLAG]\n");

    puts("Creates a '.list' file inside the ninstall folder containing the installation and \
uninstallation commands");
    puts("It lets you easily keep track of installed programs and install or uninstall them \
whenever you want\n");

    PRINT_B("OPTION\n");
    puts("\tnew:\t(Pred. option) Creates a '.list' file with the name of the program");
    puts("\t\tThe file will be open for the user to write the commands and the installation \
will automatically be executed once the file is closed");
    puts("\tedit:\tLets you edit the content of an already existing program");
    puts("\t\tIf it doesn't exists, it creates a '.list' file and lets you write the commands \
without executing the installation commands");
    puts("\tlist:\tPrints a list of every program");
    puts("\tremove:\tExecutes the uninstallation commands and gives the user the option of \
deleting the '.list' file");
    puts("\t\tThe '-y' and '-n' flags can be used to skip the question\n");

    PRINT_B("FLAG\n");
    puts("\t-y, --remove-file:\tAutomatically remove the file when the 'remove' option is used");
    puts("\t-n, --keep-file:\tKeep the file when the 'remove' option is used");
    puts("\t--help:\t\t\tPrint this information message");
    puts("\t--version:\t\tPrint version message");
}

void versionFlag() {
    puts("ninstall 1.0\n");
    puts("Made by: Leonel Giuliano");
}