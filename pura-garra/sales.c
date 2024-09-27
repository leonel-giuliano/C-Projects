#include <stdio.h>

#include "main.h"
#include "sales.h"


setupError_t setupSales(salesRecord_t *salesRecord) {
    salesRecord->saleList = NULL;
    salesRecord->fp = NULL;

    return SETUP_NOERROR;
}
