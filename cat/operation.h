#ifndef __CAT_OPERATION_H__
#define __CAT_OPERATION_H__


// Strings

#define BOLD_START "\e[1m"
#define BOLD_END "\e[m"

// Print a string in bold
#define PRINT_B(str) printf("%s%s%s", BOLD_START, str, BOLD_END)


#include "cat.h"


// Flags

void helpFlag(option_t _Option);


// Help functions

void helpPred();


#endif