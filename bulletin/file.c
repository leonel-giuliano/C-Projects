#include <stdio.h>
#include <linux/limits.h>
#include <stdint.h>
#include <string.h>

#include "file.h"


char *getDir(char *path) {
    FILE *fpConfig = fopen(CONFIG_FILE, "r");

    // This means the file hasn't been created
    if(fpConfig == NULL) strncpy(path, PRED_PATH, PATH_MAX);
    else fgets(path, PATH_MAX, fpConfig);

    return path;
}