#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <linux/limits.h>
#include <dirent.h>
#include <string.h>

#include "argop.h"

#include "ninstall.h"
#include "manage-op.h"
#include "op.h"


flagRm_t askRemove() {
    char ch;

    uint8_t loop = 0;
    // Loop the question until the value is 0 (255 times)
    // This is only in case of a strange input problem
    while(++loop) {
        printf("Do you want to delete the file [y/n]: ");
        ch = getchar();

        if(ch == 'y' || ch == 'Y') return FLAG_RM_YES;
        if(ch == 'n' || ch == 'N') return FLAG_RM_NO;

        // This happens when the input is different
        puts("\nERROR: bad input");
        // Clean the buffer
        while(getchar() != '\n');
    }

    // If the loop had a problem prevent the file form being deleted
    return FLAG_RM_NO;
}


uint8_t execCommand(const char *search, FILE *fp) {
    rewind(fp);

    uint8_t returnVal = 0;
    char *comm = NULL;
    size_t commLen = COMM_MAX;
    ssize_t nComm;

    // Go through the file until the comment is found
    while((nComm = getline(&comm, &commLen, fp)) != -1 && strcmp(comm, search));

    // Problem allocating or the str wasn't found
    if(nComm == -1) returnVal = (errno == ENOMEM) ? ENOMEM : 1;
    else {
        // Used to stop before the EOF
        uint8_t isInstall = (!strcmp(search, INSTALL_STR)) ? 1 : 0;

        // Execute every command
        while((nComm = getline(&comm, &commLen, fp)) != -1) {
            if(!strcmp(comm, "\n")) continue;

            // The installation command doesn't go to the EOF
            if(isInstall && !strcmp(comm, UNINSTALL_STR)) break;

            printf("Executing: %s", comm);
            system(comm);
        }

        // Problem allocating
        // The installation can run withouth the uninstallation comment
        if(nComm == -1 && errno == ENOMEM) returnVal = ENOMEM;
    }
    
    free(comm);
    return returnVal;
}


FILE *fopenNano(char *path, const char *program) {
    FILE *fp = fopen(path, "a+");
    if(fp == NULL) return NULL;

    // Check if the file is empty to write the comments
    fseek(fp, 0, SEEK_END);
    if(!ftell(fp)) {
        fprintf(fp, "%s\n%s", INSTALL_STR, UNINSTALL_STR);
        fflush(fp);
    }

    // Open the file in nano
    char nano[PATH_MAX + NANO_LEN];
    snprintf(nano, PATH_MAX + NANO_LEN, "nano %s", path);
    system(nano);

    return fp;
}


char *getPath(char *path, const char *program) {
    if(getDir(path) == NULL) return NULL;

    size_t len = strlen(path);
    snprintf(path + len, PATH_MAX - len, "%s.list", program);

    // Pointer to the file instead of the whole path
    return path + len;
}


char *getDir(char *path) {
    // Get home env for the ninstall folder
    char *home = getenv("HOME");
    if(home == NULL) return NULL;

    // Concat only the first part to have the file separated
    snprintf(path, PATH_MAX, "%s/%s/", home, NINSTALL_HOME_FOLDER);

    // Return folder directory
    return path;
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


/* OPTION */

void newOption(const char *program) {
    char path[PATH_MAX];
    char *fileName = getPath(path, program);

    FILE *fp = fopenNano(path, program);
    if(fp == NULL) errorHandler(ERROR_FILE, fileName);

    // Executes the installation commands
    uint8_t execVal = execCommand(INSTALL_STR, fp);
    if(execVal) {
        fclose(fp);

        if(execVal == ENOMEM) errorHandler(ERROR_NOMEM);
        errorHandler(ERROR_COMMENT, INSTALL_STR);
    }

    if(fclose(fp) == EOF) errorHandler(ERROR_FCLOSE, fileName);
}


void editOption(const char *program) {
    char path[PATH_MAX];
    char *fileName = getPath(path, program);

    FILE *fp = fopenNano(path, program);
    if(fp == NULL) errorHandler(ERROR_FILE, fileName);

    if(fclose(fp) == EOF) errorHandler(ERROR_FCLOSE, fileName);
}


void listOption() {
    char path[PATH_MAX];
    DIR *dir = opendir(getDir(path));
    if(dir == NULL) errorHandler(ERROR_DIR, path);

    if(closedir(dir)) errorHandler(ERROR_CLOSEDIR, path);
}


void removeOption(const char *program, flagRm_t flagRm) {
    char path[PATH_MAX];
    char *fileName = getPath(path, program);

    FILE *fp = fopenNano(path, program);
    if(fp == NULL) errorHandler(ERROR_FILE, fileName);

    // Executes the installation commands
    uint8_t execVal = execCommand(UNINSTALL_STR, fp);
    if(execVal) {
        fclose(fp);

        if(execVal == ENOMEM) errorHandler(ERROR_NOMEM);
        errorHandler(ERROR_COMMENT, UNINSTALL_STR);
    }

    // Close the file before deleting it
    if(fclose(fp) == EOF) errorHandler(ERROR_FCLOSE, fileName);

    // Ask to remove only if the flags weren't use
    flagRm_t flag = (has_flag_rm0 || has_flag_rm1) ? flagRm : askRemove();

    if(flag == FLAG_RM_YES) {
        printf("\nDeleting '%s'...\n", fileName);
        
        if(remove(path) == -1) errorHandler(ERROR_FILE, fileName);
        puts("File deleted");
    }
    
    else puts("The file wasn't delete");
}