#ifndef __BT_FILE_H__
#define __BT_FILE_H__


#include <stdio.h>
#include <linux/limits.h>
#include <stdint.h>


/* TEXT */

#define PRED_PATH "./bulletin.csv"
#define PRED_DIR "./"
#define PRED_FILE_NAME "bulletin"
#define FILE_TYPE ".csv"

#define CONFIG_FILE "./path.config"


/* FILE STRUCT */

typedef struct {
    uint8_t had_names;
    char path[PATH_MAX];

    FILE *fp;
} btFile_t;


// Save the pred directory or the one in the config file
char *getDir(char *_BufferPath);

// Count the first comma of every line to know the amount of students
uint8_t fgetnStudents(FILE *_Stream);

// Reads the names of the students from the file
// Returns 1 if there was a problem reading it
uint8_t fgetsStudents(bulletin_t *_Bulletin);


#endif