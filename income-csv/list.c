#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "main.h"
#include "error.h"

static item_t *list = NULL;

void addItem(FILE *fp) {
    item_t *item;
    if((item = (item_t*)malloc(sizeof(item_t))) == NULL) {
        delList();
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
}

void delList(void) {
    uint16_t exitPrevent = 0;

    while(list != NULL && exitPrevent != ITEM_LOOP) {
        item_t *delItem = list;
        list = list->next;
        free(delItem);
        // Detaches the item from the list and frees it

        exitPrevent++;
    }

    if(exitPrevent == ITEM_LOOP && list == NULL)
        puts("\nPROGRAM ERROR: Problem with the loop.");
}