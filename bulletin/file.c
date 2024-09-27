#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "main.h"
#include "bulletin.h"
#include "file.h"


int8_t fgetsMarkNames(bulletin_t *bulletin) {
    // Check if the file has a char after the student row len
    fseek(bulletin->fpData.fp, 0, SEEK_END);
    if(ftell(bulletin->fpData.fp) < STUDENTS_ROW_LEN + 1) return 0;

    // Check if it has the students row name
    rewind(bulletin->fpData.fp);
    char stRow[STUDENTS_ROW_LEN + 1];
    if(strcmp(STUDENTS_ROW, fgets(stRow, STUDENTS_ROW_LEN, bulletin->fpData.fp))) return 0;

    // Check if the next char to know if there is another mark name
    char ch;
    uint8_t isFirstMark = 1;
    markName_t *mark = NULL;

    while((ch = getc(bulletin->fpData.fp)) != '\n' && ch != ',' && ch != EOF) {
        // 'mark' points to the last element to stay in the end of the list
        if((mark = mallocMarkName(mark)) == NULL) return 1;

        // The list points to the first mark name
        if(isFirstMark) {
            bulletin->markNameList = mark;
            isFirstMark = 0;
        }

        mark->name[0] = ch;
        // Move the name a char because the first one is scanned to check if there was a mark
        fscanf(bulletin->fpData.fp, "%.*[^,]", MARK_STR_MAX - 1, mark->name + 1);

        // Skip the ','
        getc(bulletin->fpData.fp);
    }

    // This means there was a ',,' case
    if(ch == ',') return -1;

    return 0;
}


FILE *fopenBulletin(fpData_t *fpData, flags8_t *flags) {
    if((fpData->fp = fopen(fpData->path, "r+")) == NULL) {
        if((fpData->fp = fopen(fpData->path, "w+")) == NULL) return NULL;
    } else flags->was_read = 1;

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
