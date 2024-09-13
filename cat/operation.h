#ifndef __CAT_OPERATION_H__
#define __CAT_OPERATION_H__


#include <stdio.h>


/* ARGUMENTS */

// "cat [file...]"
#define ARGC_PRED_MIN 2
// "cat [option...] [file...]"
#define ARGC_OPTION_MIN 3

// "cat [file...]"
#define ARGC_PRED_MAX 2
// "cat [option...] [file...]"
#define ARGC_OPTION_MAX 3



/* TEXT */

#define BOLD_ON "\e[1m"
#define BOLD_OFF "\e[0m"

// Distance between the ascii num and the caret notation
#define ASCII_TO_CARET 64
#define CARET_ALPHABET_START 1
#define CARET_ALPHABET_END 31

// Function to print the text in bold
#define PRINT_BOLD(str) printf("%s%s%s", BOLD_ON, str, BOLD_OFF);


#include "cat.h"


/* FLAGS */

void helpFlag();
void versionFlag();


/* OPTIONS */

void multOp(multOpFlags_t _Flags, const char *_FileName);


#endif