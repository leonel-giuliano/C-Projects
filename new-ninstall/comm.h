#ifndef __NINSTALL_COMM_H__
#define __NINSTALL_COMM_H__

#include "detect-args.h"


// Arguments

// ninstall program
#define ARG_NEW_MIN 2
// ninstall edit program
#define ARG_EDIT_MIN 3
// ninstall list
#define ARG_LIST_MIN 2

// ninstall new program
#define ARG_NEW_MAX 3
// ninstall edit program
#define ARG_EDIT_MAX 3
// ninstall list
#define ARG_LIST_MAX 2


// Text

#define BOLD_ON "\033[1m"
#define BOLD_OFF "\033[0m"


// Commands

void helpComm(op_t _Operation);


// Inside functions

void printBold(const char *_String);


// Check Functions

void checkNew(int argc, argOperation_t _ArrayArgOperations[]);
void checkEdit(int argc, argOperation_t _ArrayArgOperations[]);
void checkList(int argc, argOperation_t _ArrayArgOperations[]);


// Help functions

void helpPred();
void helpNew();
void helpEdit();
void helpList();


#endif