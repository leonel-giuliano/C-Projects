#ifndef __BT_FILE_H__
#define __BT_FILE_H__


#include <stdio.h>
#include <linux/limits.h>
#include <stdint.h>


/* TEXT */

#define PRED_PATH "./bulletin.csv"

#define CONFIG_PATH "./bulletin.config"


/* FILE STRUCT */

#define was_created flags.bits.flag0

typedef union {
    struct {
        unsigned int flag0 : 1;
        unsigned int flag1 : 1;
        unsigned int flag2 : 1;
        unsigned int flag3 : 1;
        unsigned int flag4 : 1;
        unsigned int flag5 : 1;
        unsigned int flag6 : 1;
        unsigned int flag7 : 1;
    } bits;

    uint8_t data;
} flag8_t;

typedef struct {
    flag8_t flags;
    char path[PATH_MAX];
    FILE *fp;
} fpData_t;


// Selects the path and opens the file, indicating if it was created
// Returns -1 if there was a problem accessing to the config file
// Returns 1 if there was a problem creating the file
int8_t fopenBt(fpData_t *_FileData);

// Selects the path by the config file or the pred path
// Returns NULL if there was a problem accessing the config file
char *getPath(char *_Buffer);


#endif