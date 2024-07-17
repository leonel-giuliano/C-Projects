#include <stdio.h>

#include "subcomm.h"

void subcommHelp(void) {
    puts("Nunstall is a command to uninstall a listed program.\n");

    puts("USAGE:");
    puts("\tnunstall <subcommand> [file ...] <option>\n");

    puts("SUBCOMMAND:");
    puts("\t-h, --help:\tPrints the usage message\n");

    puts("OPTION:");
    puts("\t-n, --no:\tMakes sure the program file doesn't get erased without asking");
    puts("\t-y, --yes:\tErases the program file without asking\n");
}