#ifndef __NUNSTALL_SUBCOMM_H__
#define __NUNSTALL_SUBCOMM_H__

// Subcommands
#define SUBCOMM_HELP1 "-h"
#define SUBCOMM_REMOVE1 "-r"

#define SUBCOMM_HELP2 "--help"
#define SUBCOMM_REMOVE2 "--remove"

// With spaces for strstr()
#define SPACE_SUBCOMM_HELP1 " -h"
#define SPACE_SUBCOMM_REMOVE1 " -r"

#define SPACE_SUBCOMM_HELP2 " --help"
#define SPACE_SUBCOMM_REMOVE2 " --remove"

void subcommHelp(void);

#endif