#ifndef __BULLETIN_H__
#define __BULLETIN_H__


#include <stdint.h>


/* TEXT */

#define MARK_STR_MAX 100


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


#endif