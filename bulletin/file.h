#ifndef __BT_FILE_H__
#define __BT_FILE_H__


#include <stdio.h>
#include <linux/limits.h>
#include <stdint.h>


/* TEXT */

#define PRED_PATH "./bulletin.csv"

#define CONFIG_PATH "./bulletin.config"


/* FILE STRUCT */

typedef struct {
    char path[PATH_MAX];
    FILE *fp;
} fpData_t;


// Selects the path by the config file or the pred path
// Returns NULL if there was a problem accessing the config file
char *getPath(char *_Buffer);


#endif