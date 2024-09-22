#include <stdio.h>
#include <stdint.h>

#include "bulletin.h"
#include "student.h"


uint8_t asknStudents() {
    uint8_t n, loop = 0;

    while(++loop) {
        printf("Amount of students: ");
        scanf("%hhu", &n);

        if(n) return n;
        puts("ERROR: The amounts of students can't be 0"); 
    }

    // In case there is an error (looped over 255 times)
    return 0;
}


uint8_t askNames(bulletin_t *bulletin) {
    // Iterate through every student to scan the name
    for(uint8_t i = 0; i < bulletin->len; i++) {
        printf("Student %hhu: ", i + 1);

        if(fgetsClean(bulletin->students[i].name, NAME_MAX, stdin) == NULL)
            return 1;
    }

    return 0;
}