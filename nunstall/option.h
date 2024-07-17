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

const char *optionArray[AMOUNT_OPTION][SAME_OPTION] = {
    { OPTION_YES1, OPTION_YES2 },
    { OPTION_NO1, OPTION_NO2 }
};

extern const char *optionArray[AMOUNT_OPTION][SAME_OPTION];

#endif