#ifndef __BULLETIN_H__
#define __BULLETIN_H__


#ifdef __linux__
    #include <linux/limits.h>
#else
    #include <limits.h>
#endif

#include <stdio.h>
#include <stdint.h>


/* TEXT */

#define MARK_STR_MAX 100
#define ST_STR_MAX 100


/* SETUP FLAGS */

#define was_read setupFlags->bits.flag0


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
    SETUP_NOGOTO
};


// Proccess before the menu is executed
setupError_t bulletinSetup(bulletin_t *_Bulletin);


#endif
