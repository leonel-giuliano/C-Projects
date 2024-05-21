#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "error.h"

static item_t *list = NULL;

void delList(void) {
    uint16_t exitPrevent = 0;
    item_t *delItem = list;

    while(list != NULL && ITEM_LOOP != exitPrevent) {
        list = list->next;
        free(delItem);

        exitPrevent++;
    }
}