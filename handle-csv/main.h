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

void scanstr(char _Buffer[], int _Length, FILE *_Stream);
// Scans a string and clears the remaing data