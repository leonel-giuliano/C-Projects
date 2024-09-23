#ifndef __BT_FILE_H__
#define __BT_FILE_H__


#include <stdio.h>
#include <linux/limits.h>


/* FILE STRUCT */

typedef struct {
    char path[PATH_MAX];
    FILE *fp;
} fpData_t;


#endif