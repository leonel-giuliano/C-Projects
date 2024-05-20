#include <stdint.h>

#define DATE_LENGTH 9       /* mm/dd/yy */
#define DESC_LENGTH 100

typedef struct {
    char date[DATE_LENGTH];
    char description[DESC_LENGTH];
    uint32_t income;
    uint32_t outcome;
    uint32_t salary;
    // Date,Description,Income,Outcome,Salary
}data_t;