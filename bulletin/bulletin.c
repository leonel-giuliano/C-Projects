#include <stdio.h>

#include "main.h"
#include "bulletin.h"
#include "file.h"


setupError_t bulletinSetup(bulletin_t *bulletin) {
    bulletin->markNameList = NULL;
    bulletin->students = NULL;
    bulletin->fpData.fp = NULL;

    if(getPath(bulletin->fpData.path) == NULL) {
        errorHandler(ERROR_FILE, CONFIG_PATH);
        return SETUP_NOGOTO;
    }

    return SETUP_NOERROR;
}
