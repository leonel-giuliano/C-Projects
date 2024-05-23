// ARGUMENTS
#define ARGC_PARAM 2
// 'main.exe file.csv'
enum {
    ARGV_PATH,
    ARGV_FILE
};
// Argv values

#define STR_LENGTH 100
#define GRADE 248           /* ° */

// MENU
#define MENU_PARAM char **columnNames, uint8_t columnNum, FILE *fpData
#define MENU_ARG columnNames, columnNum, fpData
// Arguments and parameters for the menu functions

typedef enum {
    MENU_START,
    MENU_ADD,
    MENU_READ_ROW,
    MENU_END
}menuState_t;

void scanstr(char _Buffer[], int _Length, FILE *_Stream);
// Scans a string and clears the remaing data

void freeArrPtr(char **_ArrPtr, uint8_t _Length);

// MENU FUNCTIONS
void menu(menuState_t *_State, MENU_PARAM);
void menuAdd(MENU_PARAM);
void menuReadRow(MENU_PARAM);
void menuEnd(MENU_PARAM);