#ifndef __BULLETIN_H__
#define __BULLETIN_H__


#include <stdint.h>


/* TEXT */

#define MARK_STR_MAX 100


/* ERROR EVENTS */

typedef uint8_t errorEvent_t;
enum {
    ERROR_FILE
};


#include "student.h"
#include "file.h"


/* BULLETIN STRUCT */

typedef struct _markName_t {
    char name[MARK_STR_MAX];
    struct _markName_t *next;
} markName_t;

typedef struct {
    uint8_t len;

    markName_t *markNameList;
    student_t *students;

    fpData_t fpData;
} bulletin_t;


// Sets the 'bulletin_t' pointers to NULL
bulletin_t initBt();

uint8_t errorHandler(errorEvent_t _ErrorEvent, ...);


#endif