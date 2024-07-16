#include <stdio.h>

#include "commands.h"

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
    puts("\t-p, --pred-path:\tMakes the ninstall folder be '~/ninstall'");
    puts("\t-d, --directory:\tChanges the ninstall folder");

    printf("FILE:\t Enter only the name and automatically gets converted into a '%s'\n", FILE_TYPE);
}