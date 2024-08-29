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

#define BOLD_ON "\e[1m"
#define BOLD_OFF "\e[0m"

// "nano "
#define NANO_LEN 5
// "# Installation"
#define INSTALL_LEN 14
// "# Uninstallation"
#define UNINSTALL_LEN 16
// ".list"
#define TYPE_LEN 5


#include "ninstall.h"


// Commands

void helpComm(op_t _Operation);
void newComm(const char *_ProgramName);
void editComm(const char *_ProgramName);
void listComm();


// Inside functions

void printBold(const char *_String);
void getProgramPath(char *_Buffer, const char *_ProgramName);
void exeInstallation(FILE *_Stream);


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