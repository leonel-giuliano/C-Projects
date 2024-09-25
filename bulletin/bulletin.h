#ifndef __BULLETIN_H__
#define __BULLETIN_H__


#ifdef __linux__
    #include <linux/limits.h>
#elif __MINGW32__
    #include <limits.h>
#endif

#include <stdio.h>
#include <stdint.h>


/* TEXT */

#define MARK_STR_MAX 100
#define STUDENT_STR_MAX 50


/* STUDENT STRUCT */

typedef struct _mark_t {
    uint8_t value;
    struct _mark_t *next;
} mark_t;

typedef struct {
    char name[STUDENT_STR_MAX];
    mark_t *markList;
} student_t;


/* FILE STRUCT */

#define was_read flags.bits.flag0
#define has_mark_names flags.bits.flag1
#define has_students flags.bits.flag2

typedef union {
    struct {
        unsigned int flag0 : 1;
        unsigned int flag1 : 1;
        unsigned int flag2 : 1;
        unsigned int flag3 : 1;
        unsigned int flag4 : 1;
        unsigned int flag5 : 1;
        unsigned int flag6 : 1;
        unsigned int flag7 : 1;
    } bits;

    uint8_t data;
} flag8_t;

typedef struct {
    flag8_t flags;
    char path[PATH_MAX];
    FILE *fp;
} fpData_t;


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


/* ERROR EVENTS */

typedef uint8_t errorEvent_t;
enum {
    ERROR_READ_FILE,

    ERROR_FILE,
    ERROR_INPUT,
    ERROR_MALLOC
};


// Sets the 'bulletin_t' pointers to NULL
bulletin_t initBt();

// Gets rid of the '\n' and cleans the stdin
// Returns NULL if no char was read
char *fgetsClean(char *_Buffer, int _BufferSize, FILE *_Stream);

uint8_t errorHandler(errorEvent_t _ErrorEvent, ...);


#endif