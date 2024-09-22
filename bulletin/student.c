#include <stdio.h>
#include <stdint.h>

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