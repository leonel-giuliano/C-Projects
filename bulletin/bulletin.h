#ifndef __BULLETIN_H__
#define __BULLETIN_H__


#ifdef __linux__
    #include <linux/limits.h>
#else
    #include <limits.h>
#endif

#include <stdio.h>
#include <stdint.h>


#define MARK_EMPTY -1


/* TEXT */

#define MARK_STR_MAX 100
#define ST_STR_MAX 50


/* SETUP FLAGS */

#define was_read bits.flag0
#define has_data bits.flag1
#define has_students bits.flag2
#define has_mark_name bits.flag3


/* BULLETIN STRUCT */

typedef struct _markName_t {
    char name[MARK_STR_MAX];
    struct _markName_t *next;
} markName_t;


typedef struct _mark_t {
    int8_t value;
    struct _mark_t *next;
} mark_t;


typedef struct {
    char name[ST_STR_MAX];
    mark_t *markList;
} student_t;


typedef struct {
    char path[PATH_MAX];
    FILE *fp;
} fpData_t;


typedef struct {
    uint8_t len;

    markName_t *markNameList;
    student_t *students;

    fpData_t fpData;
} bulletin_t;


/* SETUP EXIT */

typedef uint8_t setupError_t;
enum {
    SETUP_NOERROR,
    SETUP_NOGOTO,
    SETUP_MARK_NAME_LIST,
    SETUP_MARK_LIST
};


// Proccess before the menu is executed
setupError_t bulletinSetup(bulletin_t *_Bulletin);

// Scan the names of all the students
// Returns NULL if there was a problem reading the input
uint8_t getsStudents(bulletin_t *_Bulletin);

// Scan user input to know the amount of students
// Returns 0 if there was a problem
uint8_t getnStudents();


/* ALLOC MARKS */

// Allocates a mark name at the end of the list
// Returns NULL if there was a problem allocating
mark_t *mallocMark(mark_t *_MarkList);

// Free the mark list from all the students
void freeAllMarks(bulletin_t *_Bulletin);

// Free every element in the list
void freeMarkList(mark_t *_MarkList);


// Allocates a mark name at the end of the list
// Returns NULL if there was a problem allocating
markName_t *mallocMarkName(markName_t *_MarkNameList);

// Free every element in the list
void freeMarkNameList(markName_t *_MarkNameList);


#endif
