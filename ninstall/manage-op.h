#ifndef __NINSTALL_MANAGE_H__
#define __NINSTALL_MANAGE_H__


#include <stdint.h>


/* ENUM */

enum {
    TYPE_FLAG = 1,
    TYPE_OPTION
};

typedef uint8_t flag_t;
enum {
    FLAG_HELP = 1,
    FLAG_VERSION
};


#endif