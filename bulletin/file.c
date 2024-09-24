#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>

#include "bulletin.h"
#include "file.h"


int8_t fopenBt(fpData_t *fpData) {
    // Problem reading the file path from the config file
    if(getPath(fpData->path) == NULL) return -1;

    if((fpData->fp = fopen(fpData->path, "r+")) == NULL) {
        if((fpData->fp = fopen(fpData->path, "w+")) == NULL) return 1;

        fpData->was_created = 1;
    } else fpData->was_created = 0;

    return 0;
}


char *getPath(char *path) {
    FILE *fpConfig = fopen(CONFIG_PATH, "r");
    // This is when there is a problem accessing the file
    if(fpConfig == NULL && errno != ENONET) return NULL;

    if(fpConfig == NULL) {
        strncpy(path, PRED_PATH, PATH_MAX);

        return path;
    }

    // If the file exists but there is no path
    if(fgetsClean(path, PATH_MAX, fpConfig) == NULL)
        strncpy(path, PRED_PATH, PATH_MAX);

    fclose(fpConfig);

    return path;
}