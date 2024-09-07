#include <stdio.h>

#include "operation.h"
#include "cat.h"


// Flags

void helpFlag(option_t option) {
    switch(option) {
        case OPTION_PRED:
            helpPred();
            break;
    }
}

void versionFlag() {
    puts("Personal cat command for test.");
}


// Options

void showAllOption(FILE *fp) {
    // Print every char one by one
    char ch;
    while((ch = getc(fp)) != EOF) putchar(ch);
}

void numBlankOption(FILE *fp) {
    // This will help to compare the lines
    char ch0 = '\n', ch1;
    size_t num = 0;

    while((ch1 = getc(fp)) != EOF) {
        // Print the num at the start of a new line
        // but ignore it if it's an empty line
        if(ch0 == '\n' && ch1 != '\n') printf("%llu\t", ++num);

        putchar(ch1);

        // Save the last char
        ch0 = ch1;
    }
}


// Help functions

void helpPred() {
    PRINT_B("USAGE:\n");
    puts("\tcat [option] [file]...\n");

    puts("Concatenate FILE(s) to standard output.");
    puts("Without FILE, or when FILE is -, reeds the standard input.\n");

    PRINT_B("FLAGS:\n");
    puts("\t--help\tdisplay this help and exit");
    puts("\t--version\toutput version and exit");

    PRINT_B("OPTIONS:\n");
    puts("\t-A, --show-all\tequivalent to -vET");
    puts("\t-b, --number-nonblank\tnumber nonempty output lines, overrides -n");
    puts("\t-e\t\tequivalent to -vE");
    puts("\t-E, --show-ends\tdisplay $ at end of each line");
    puts("\t-n, --number\tnumber all output lines");
    puts("\t-s, --squeeze-blank\tsuppress repeated empty output lines");
    puts("\t-t\t\tequivalent to -vT");
    puts("\t-T, --show-tabs\tshows the tab characters such as ^I");
    puts("\t-v, --show-nonprinting\tuses the notation ^ y M-, except for LFD and TAB\n");
}