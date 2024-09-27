#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "main.h"
#include "bulletin.h"
#include "file.h"


FILE *fopenBulletin(fpData_t *fpData, flags8_t *setupFlags) {
    if((fpData->fp = fopen(fpData->path, "r+")) == NULL) {
        if((fpData->fp = fopen(fpData->path, "w+")) == NULL) return NULL;
    } else was_read = 1;

    return fpData->fp;
}


char *getPath(char *path) {
    FILE *fp = fopen(CONFIG_PATH, "rb");
    if(fp == NULL) {
        // Problem trying to access the config file
        if(errno != ENOENT) return NULL;

        strncpy(path, PRED_PATH, PATH_MAX);
    } else {
        // Read the path byte by byte
        char ch;
        uint16_t i = 0;

        while(i < PATH_MAX && fread(&ch, sizeof(char), 1, fp) && ch != '\0')
            path[i++] = ch;

        if(i) path[i] = '\0';
        // In case there was no data
        else strncpy(path, PRED_PATH, PATH_MAX);

        fclose(fp);
    }

    return path;
}
