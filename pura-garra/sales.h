#ifndef __SALES_H__
#define __SALES_H__


#ifdef __linux__
    #include <linux/limits.h>
#else
    #include <limits.h>
#endif

#include <stdio.h>
#include <stdint.h>


/* TEXT */

#define STR_MAX 100
#define PAY_MAX 20


/* SALE STRUCT */

typedef struct _sale_t {
    char product[STR_MAX];
    uint32_t value;
    char payMethod[PAY_MAX];

    struct _sale_t *next;
} sale_t;


/* SALES RECORD STRUCT */

typedef struct {
    char path[PATH_MAX];
    sale_t *saleList;
    FILE *fp;
} saleRecord_t;


#endif
