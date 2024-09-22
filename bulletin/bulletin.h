#ifndef __BULLETIN_H__
#define __BULLETIN_H__


#include "student.h"
#include "file.h"


/* BULLETIN STRUCT */

#define fp fileData->file

typedef struct {
    uint8_t len;

    markName_t *markName = NULL;
    student_t *students = NULL;

    btFile_t *fileData = NULL;
} bulletin_t;


#endif