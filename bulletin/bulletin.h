#ifndef __BULLETIN_H__
#define __BULLETIN_H__


#include "student.h"
#include "file.h"


/* BULLETIN STRUCT */

#define file fileData.fp
#define pathStr fileData.path

typedef struct {
    uint8_t len;

    markName_t *markName = NULL;
    student_t *students = NULL;

    btFile_t fileData;
} bulletin_t;


/* ERROR EVENTS */

typedef uint8_t errorEvent_t;
enum {
    ERROR_FILE
};


// Opens the file and gets the length (amount of students)
// Returns 1 in case the file couldn't been created
uint8_t fopenLen(bulletin_t *_Bulletin);

void errorHandler(errorEvent_t _ErrorEvent, ...);


#endif