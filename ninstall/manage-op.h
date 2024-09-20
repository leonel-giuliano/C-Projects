#ifndef __NINSTALL_MANAGE_H__
#define __NINSTALL_MANAGE_H__


#include <stdint.h>

#include "argop.h"


/* ENUM */

enum {
    TYPE_FLAG = 1,
    TYPE_OPTION,
    TYPE_FLAG_RM
};

typedef uint8_t flag_t;
enum {
    FLAG_HELP = 1,
    FLAG_VERSION
};

typedef uint8_t option_t;
enum {
    OPTION_PRED,
    OPTION_NEW,
    OPTION_EDIT,
    OPTION_LIST,
    OPTION_REMOVE
};


/* MANAGE */

void manageFlag(int argc, argOp_t _ArgOp[]);
void manageOption(int argc, char *argv[], argOp_t _ArgOp[]);


/* CHECK */

void checkOption(int argc, argOp_t _ArgOp[], option_t _Option);
void checkNew(int argc, argOp_t _ArgOp[]);
void checkList(int argc, argOp_t _ArgOp[]);
void checkRemove(int argc, argOp_t _ArgOp[]);


/* SELECT */

void selectOption(int argc, char *argv[], option_t _Option);


#endif