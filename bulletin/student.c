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

        puts("ERROR: the amount of students can't be 0");
    }

    // If there was a problem in the loop
    return 0;
}