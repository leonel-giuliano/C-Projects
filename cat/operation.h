#ifndef __CAT_OPERATION_H__
#define __CAT_OPERATION_H__


#include <stdio.h>


/* TEXT */

#define BOLD_ON "\e[1m"
#define BOLD_OFF "\e[0m"

// Distance between the ascii num and the caret notation
#define ASCII_TO_CARET 64

// Function to print the text in bold
#define PRINT_BOLD(str) printf("%s%s%s", BOLD_ON, str, BOLD_OFF);


/* FLAGS */

void helpFlag();
void versionFlag();


#endif