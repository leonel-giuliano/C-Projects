#include <stdint.h>

#define DATE_LENGTH 9       /* mm/dd/yy */
#define DESC_LENGTH 10

typedef struct _item {
    char date[DATE_LENGTH];
    char description[DESC_LENGTH];

    uint32_t income;
    uint32_t outcome;
    uint32_t salary;
    // Date,Description,Income,Outcome,Salary

    struct _item *next;
}item_t;

void addItem(FILE *_Stream);
void delList(void);