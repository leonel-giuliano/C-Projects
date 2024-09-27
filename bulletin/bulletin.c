#include <stdio.h>

#include "bulletin.h"


setupError_t bulletinSetup(bulletin_t *bulletin) {
    bulletin->markNameList = NULL;
    bulletin->students = NULL;
    bulletin->fpData.fp = NULL;

    return SETUP_NOERROR;
}
