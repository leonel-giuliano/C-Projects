#ifndef __NUNSTALL_OPTION_H__
#define __NUNSTALL_OPTION_H__

#include <string.h>

// Info about options
#define AMOUNT_OPTION 2
#define SAME_OPTION 2

// Options
#define OPTION_YES1 "-y"
#define OPTION_NO1 "-n"

#define OPTION_YES2 "--yes"
#define OPTION_NO2 "--no"

// Index of the options
enum {
    IX_OPTION_YES,
    IX_OPTION_NO
};

enum {
    IX_OPTION_1,
    IX_OPTION_2
};

// Compare str with an option
#define CMP_OPTION(arg, option) !strcmp(arg, optionArray[option][IX_OPTION_1]) || !strcmp(arg, optionArray[option][IX_OPTION_2])

// Array that contains every option
const char *optionArray[AMOUNT_OPTION][SAME_OPTION] = {
    { OPTION_YES1, OPTION_YES2 },
    { OPTION_NO1, OPTION_NO2 }
};

extern const char *optionArray[AMOUNT_OPTION][SAME_OPTION];

#endif