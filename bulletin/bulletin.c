#include <stdio.h>
#include <errno.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

#include "bulletin.h"
#include "student.h"
#include "file.h"


int main() {
    uint8_t retVal = 0;
    bulletin_t bulletin;

    // Get the file and the lenght
    // Exit the function if there was a problem creating the file
    if(fopenLen(&bulletin)) return errorHandler(ERROR_FILE, bulletin.pathStr);
    

    close_file:
        fclose(bulletin.file);

        return retVal;
}


uint8_t fopenLen(bulletin_t *bulletin) {
    // Try to open the file if it exists
    if((bulletin->file = fopen(getDir(bulletin->pathStr), "r+")) == NULL) {
        if((bulletin->file = fopen(bulletin->pathStr, "w+")) == NULL)
            return 1;

        bulletin->len = asknStudents();
    }
    // The amount of students is taken from the file
    // If it didn't have any student, asks the user
    else if(!(bulletin->len = fgetnStudents(bulletin->file)))
        bulletin->len = asknStudents();

    return 0;
}


uint8_t errorHandler(errorEvent_t error, ...) {
    va_list arg;
    va_start(arg, error);

    printf("bulletin: ");

    switch(error) {
        case ERROR_FILE:
            printf("cannot access '%s': %s", va_arg(arg, const char *), strerror(errno));
            break;
    }

    va_end(arg);

    return 1;
}