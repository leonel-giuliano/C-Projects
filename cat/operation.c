#include <stdio.h>

#include "operation.h"


/* FLAGS */

void helpFlag() {
    PRINT_BOLD("USAGE:\n");
    puts("\tcat [option]... [file]...");
    puts("Concatenate FILE(s) to standard output.\n");

    puts("With no FILE, or when FILE is -, read standard input.\n");

    PRINT_BOLD("FLAGS:\n");
    puts("\t--help\tdisplay this help and exit");
    puts("\t--version\toutput version information and exit\n");

    PRINT_BOLD("OPTIONS:\n");
    puts("\t-A, --show-all\tequivalent to -vET");
    puts("\t-b, --number-nonblank\tnumber nonempty output lines, overrides -n");
    puts("\t-e\t\tequivalent to -vET");
    puts("\t-E, --show-ends\tdisplay $ at end of each line");
    puts("\t-n, --number\tnumber all output lines");
    puts("\t-s, --squeeze-blank\tsuppress repeated empty output lines");
    puts("\t-t\t\tequivalent to -vT");
    puts("\t-T, --show-tabs\tdisplay TAB characters as ^I");
    puts("\t-u\t\t(ignored)");
    puts("\t-v, --show-nonprinting\tuse ^ and M- notation, except for LFD and TAB\n");

    PRINT_BOLD("EXAMPLES:\n");
    puts("\tcat f - g\tOutput f's contents, then standard input, then g's contents.");
    puts("\tcat\tCopy standard input to standard output.\n");

    puts("GNU coreutils online help: <https://www.gnu.org/software/coreutils/>");
    puts("Full documentation <https://www.gnu.org/software/coreutils/cat> or available locally via: info '(coreutils) cat invocation'");
}

void versionFlag() {
    puts("cat (GNU coreutils) 9.1");
    puts("Copyright (C) 2022 Free Software Foundation, Inc");
    puts("License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.");
    puts("This is free software: you are free to change and redistribute it.");
    puts("There is NO WARRANTY, to the extent permitted by law.\n");
    puts("Written by Torbjorn Granlund and Richard M. Stallman.");
}