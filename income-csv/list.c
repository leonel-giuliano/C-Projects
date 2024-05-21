#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "main.h"
#include "error.h"

static item_t *list = NULL;

void addItem(FILE *fp) {
    item_t *item;
    if((item = (item_t*)malloc(sizeof(item_t))) == NULL) {
        fclose(fp);

        errorHandler(ERROR_MALLOC);
    }

    printf("Date: ");
    scanStr(item->date, DATE_LENGTH, stdin);
    printf("Description: ");
    scanStr(item->description, DESC_LENGTH, stdin);
    printf("Income: ");
    scanf(" %u", &(item->income));
    printf("Outcome: ");
    scanf(" %u", &(item->outcome));
    printf("Salary: ");
    scanf(" %u", &(item->salary));

    printf("%s\n", item->date);
    printf("%s\n", item->description);
}

void delList(void) {
    uint16_t exitPrevent = 0;
    item_t *delItem = list;

    while(list != NULL && exitPrevent != ITEM_LOOP) {
        list = list->next;
        free(delItem);

        exitPrevent++;
    }
}