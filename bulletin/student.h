#ifndef __BT_STUDENT_H__
#define __BT_STUDENT_H__


#include <stdio.h>
#include <stdint.h>


/* TEXT */

#define ST_NAME_MAX 50
#define MARK_NAME_MAX 100


/* STUDENT STRUCT */

typedef struct _markName_t {
    char name[MARK_NAME_MAX];

    struct _markName_t *next;
} markName_t;

typedef struct _mark_t {
    uint8_t value;

    struct _mark_t *next;
} mark_t;

typedef struct {
    char name[ST_NAME_MAX];

    mark_t *mark;
} student_t;


// Asks the user for the amount of students
uint8_t asknStudents();


#endif