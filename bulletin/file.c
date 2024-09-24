#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>

#include "bulletin.h"
#include "file.h"


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