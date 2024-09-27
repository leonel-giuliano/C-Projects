#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "sales.h"
#include "file.h"


char *getPath(char *path) {
    FILE *fpConfig = fopen(CONFIG_PATH, "rb");
    if(fpConfig == NULL) {
        // Problem trying to open the file
        if(errno != ENOENT) return NULL;

        strncpy(path, PRED_PATH, PATH_MAX);
    } else {
        // Read path byte by byte
        char ch;
        uint16_t i = 0;

        while(i < PATH_MAX && fread(&ch, sizeof(char), 1, fpConfig) && ch != '\0')
            path[i++] = ch;

        if(i) path[i] = '\0';
        // In case the file couldn't been read
        else strncpy(path, PRED_PATH, PATH_MAX);

        fclose(fpConfig);
    }

    return path;
}