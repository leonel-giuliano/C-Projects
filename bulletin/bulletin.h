#ifndef __BULLETIN_H__
#define __BULLETIN_H__


#include "student.h"
#include "file.h"


/* BULLETIN STRUCT */

#define is_fcreated fileData.is_created
#define pathStr fileData.path
#define file fileData.fp

typedef struct {
    uint8_t len;

    markName_t *markName;
    student_t *students;

    btFile_t fileData;
} bulletin_t;


/* ERROR EVENTS */

typedef uint8_t errorEvent_t;
enum {
    ERROR_INPUT,

    ERROR_FILE,
    ERROR_NOMEM
};


// Opens the file and gets the length (amount of students)
// Returns the bool indicating if the file was 'r+' or 'w+'
// Returns -1 in case the file couldn't been created
int8_t fopenLen(bulletin_t *_Bulletin);

// Scan a string using 'fgets()' and gets rid of the '\n'
// or flushes the input buffer for the stdin
// Returns NULL if it didn't scan any char (because of '\n' or EOF)
char *fgetsClean(char *_Buffer, int _nChars, FILE *_Stream);

uint8_t errorHandler(errorEvent_t _ErrorEvent, ...);


#endif