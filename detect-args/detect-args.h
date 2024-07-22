#ifndef __DETECT_ARGS_H__
#define __DETECT_ARGS_H__

#include <stdint.h>


// Flags
#define HAS_INTERRUPTION flag.flag0
#define BAD_USAGE flag.flag1
#define HAS_COMMAND flag.flag2
#define HAS_OPTION flag.flag3

typedef union {
    uint8_t data;

    struct {
        unsigned int flag0 : 1;
        unsigned int flag1 : 1;
        unsigned int flag2 : 1;
        unsigned int flag3 : 1;
        unsigned int flag4 : 1;
        unsigned int flag5 : 1;
        unsigned int flag6 : 1;
        unsigned int flag7 : 1;
    } flag;
}flags_t;


// Functions

// Detects in which category does every argument correspond
// _AllPosibleValues: Command - Option "co"
void detectArgs(int _NumOfArguments, char *_Arguments[], const char *_AllPossibleValues, ...);

#endif