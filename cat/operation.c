#include <stdio.h>

#include "operation.h"
#include "cat.h"


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


/* OPTIONS */

void multOp(multOpFlags_t multOpFlags, const char *name) {
    FILE *fp = NULL;
    if((fp = fopen(name, "r")) == NULL) errorHandler(ERROR_FILE, name);

    // Used for '-n' or '-b'
    size_t line = 0;

    // Starts being equal to '\n' to compare in the case of '-b'
    char lastCh = '\n', newCh;
    while((newCh = getc(fp)) != EOF) {
        // In case there is a new line
        if(newCh == '\n') {
            // Check respective option with the property
            if(
                has_mult_b && lastCh != '\n'
                    ||
                // This is to overwrite '-n' if '-b'
                !has_mult_b && has_mult_n
            )
                printf("%llu\t", ++line);
        }

        // Print end of the line $ before the char in '-E'
        if(has_mult_E && newCh == '\n') putchar('$');

        // Change the output in the '-T' for TAB
        if(has_mult_T && newCh == '\t') {
            newCh = 'I';
            
            putchar('^');
        }

        // Do not print blank space with '-s'
        if(!(has_mult_s && lastCh == '\n' && newCh == '\n'))
            putchar(newCh);


        // Save the last char for later
        lastCh = newCh;
    }

    putchar('\n');

    fclose(fp);
}