#include <stdio.h>

#include "argop.h"

#include "ninstall.h"
#include "manage-op.h"
#include "op.h"


/* FLAGS */

void helpFlag(int argc, argOp_t argOp[]) {
    if(!has_option) helpPred();
}


/* HELP */

void helpPred() {
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
    puts("\t--help:\tPrint information message about the program or option");
    puts("\t--version:\tPrint version message");
}