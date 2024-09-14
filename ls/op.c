#include <stdio.h>

#include "op.h"


/* FLAG */

void helpFlag() {
    printf("Usage: ls [OPTION]... [FILE]...\n");
    printf("List information about the FILEs (the current directory by default).\n");
    printf("Sort entries alphabetically if none of -cftuvSUX nor --sort is specified.\n\n");

    printf("Mandatory arguments to long options are mandatory for short options too.\n");
    printf("  -a, --all                  do not ignore entries starting with .\n");
    printf("  -A, --almost-all           do not list implied . and ..\n");
    printf("      --author               with -l, print the author of each file\n");
    printf("  -b, --escape               print C-style escapes for nongraphic characters\n");
    printf("      --block-size=SIZE      with -l, scale sizes by SIZE when printing them;\n");
    printf("                             e.g., '--block-size=M'; see SIZE format below\n\n");

    printf("  -B, --ignore-backups       do not list implied entries ending with ~\n");
    printf("  -c                         with -lt: sort by, and show, ctime (time of last\n");
    printf("                             modification of file status information);\n");
    printf("                             with -l: show ctime and sort by name;\n");
    printf("                             otherwise: sort by ctime, newest first\n\n");

    printf("  -C                         list entries by columns\n");
    printf("      --color[=WHEN]         color the output WHEN; more info below\n");
    printf("  -d, --directory            list directories themselves, not their contents\n");
    printf("  -D, --dired                generate output designed for Emacs' dired mode\n");
    printf("  -f                         list all entries in directory order\n");
    printf("  -F, --classify[=WHEN]      append indicator (one of */=>@|) to entries WHEN\n");
    printf("      --file-type            likewise, except do not append '*'\n");
    printf("      --format=WORD          across -x, commas -m, horizontal -x, long -l,\n");
    printf("                             single-column -1, verbose -l, vertical -C\n\n");

    printf("      --full-time            like -l --time-style=full-iso\n");
    printf("  -g                         like -l, but do not list owner\n");
    printf("      --group-directories-first\n");
    printf("                             group directories before files;\n");
    printf("                             can be augmented with a --sort option, but any\n");
    printf("                             use of --sort=none (-U) disables grouping\n\n");

    printf("  -G, --no-group             in a long listing, don't print group names\n");
    printf("  -h, --human-readable       with -l and -s, print sizes like 1K 234M 2G etc.\n");
    printf("      --si                   likewise, but use powers of 1000 not 1024\n");
    printf("  -H, --dereference-command-line\n");
    printf("                             follow symbolic links listed on the command line\n");
    printf("      --dereference-command-line-symlink-to-dir\n");
    printf("                             follow each command line symbolic link\n");
    printf("                             that points to a directory\n\n");

    printf("      --hide=PATTERN         do not list implied entries matching shell PATTERN\n");
    printf("                             (overridden by -a or -A)\n\n");

    printf("      --hyperlink[=WHEN]     hyperlink file names WHEN\n");
    printf("      --indicator-style=WORD\n");
    printf("                             append indicator with style WORD to entry names:\n");
    printf("                             none (default), slash (-p),\n");
    printf("                             file-type (--file-type), classify (-F)\n\n");

    printf("  -i, --inode                print the index number of each file\n");
    printf("  -I, --ignore=PATTERN       do not list implied entries matching shell PATTERN\n");
    printf("  -k, --kibibytes            default to 1024-byte blocks for file system usage;\n");
    printf("                             used only with -s and per directory totals\n\n");

    printf("  -l                         use a long listing format\n");
    printf("  -L, --dereference          when showing file information for a symbolic\n");
    printf("                             link, show information for the file the link\n");
    printf("                             references rather than for the link itself\n\n");

    printf("  -m                         fill width with a comma separated list of entries\n");
    printf("  -n, --numeric-uid-gid      like -l, but list numeric user and group IDs\n");
    printf("  -N, --literal              print entry names without quoting\n");
    printf("  -o                         like -l, but do not list group information\n");
    printf("  -p, --indicator-style=slash\n");
    printf("                             append / indicator to directories\n\n");
    printf("  -q, --hide-control-chars   print ? instead of nongraphic characters\n");
    printf("      --show-control-chars   show nongraphic characters as-is (the default,\n");
    printf("                             unless program is 'ls' and output is a terminal)\n\n");

    printf("  -Q, --quote-name           enclose entry names in double quotes\n");
    printf("      --quoting-style=WORD   use quoting style WORD for entry names:\n");
    printf("                             literal, locale, shell, shell-always,\n");
    printf("                             shell-escape, shell-escape-always, c, escape\n");
    printf("                             (overrides QUOTING_STYLE environment variable)\n\n");

    printf("  -r, --reverse              reverse order while sorting\n");
    printf("  -R, --recursive            list subdirectories recursively\n");
    printf("  -s, --size                 print the allocated size of each file, in blocks\n");
    printf("  -S                         sort by file size, largest first\n");
    printf("      --sort=WORD            sort by WORD instead of name: none (-U), size (-S),\n");
    printf("                             time (-t), version (-v), extension (-X), width\n\n");

    printf("      --time=WORD            change the default of using modification times;\n");
    printf("                               access time (-u): atime, access, use;\n");
    printf("                               change time (-c): ctime, status;\n");
    printf("                               birth time: birth, creation;\n");
    printf("                             with -l, WORD determines which time to show;\n");
    printf("                             with --sort=time, sort by WORD (newest first)\n\n");

    printf("      --time-style=TIME_STYLE\n");
    printf("                             time/date format with -l; see TIME_STYLE below\n");
    printf("  -t                         sort by time, newest first; see --time\n");
    printf("  -T, --tabsize=COLS         assume tab stops at each COLS instead of 8\n");
    printf("  -u                         with -lt: sort by, and show, access time;\n");
    printf("                             with -l: show access time and sort by name;\n");
    printf("                             otherwise: sort by access time, newest first\n\n");

    printf("  -U                         do not sort; list entries in directory order\n");
    printf("  -v                         natural sort of (version) numbers within text\n");
    printf("  -w, --width=COLS           set output width to COLS.  0 means no limit\n");
    printf("  -x                         list entries by lines instead of by columns\n");
    printf("  -X                         sort alphabetically by entry extension\n");
    printf("  -Z, --context              print any security context of each file\n");
    printf("      --zero                 end each output line with NUL, not newline\n");
    printf("  -1                         list one file per line\n");
    printf("      --help        display this help and exit\n");
    printf("      --version     output version information and exit\n\n");

    printf("The SIZE argument is an integer and optional unit (example: 10K is 10*1024).\n");
    printf("Units are K,M,G,T,P,E,Z,Y (powers of 1024) or KB,MB,... (powers of 1000).\n");
    printf("Binary prefixes can be used, too: KiB=K, MiB=M, and so on.\n\n");

    printf("The TIME_STYLE argument can be full-iso, long-iso, iso, locale, or +FORMAT.\n");
    printf("FORMAT is interpreted like in date(1).  If FORMAT is FORMAT1<newline>FORMAT2,\n");
    printf("then FORMAT1 applies to non-recent files and FORMAT2 to recent files.\n");
    printf("TIME_STYLE prefixed with 'posix-' takes effect only outside the POSIX locale.\n");
    printf("Also the TIME_STYLE environment variable sets the default style to use.\n\n");

    printf("The WHEN argument defaults to 'always' and can also be 'auto' or 'never'.\n\n");

    printf("Using color to distinguish file types is disabled both by default and\n");
    printf("with --color=never.  With --color=auto, ls emits color codes only when\n");
    printf("standard output is connected to a terminal.  The LS_COLORS environment\n");
    printf("variable can change the settings.  Use the dircolors(1) command to set it.\n\n");

    printf("Exit status:\n");
    printf(" 0  if OK,\n");
    printf(" 1  if minor problems (e.g., cannot access subdirectory),\n");
    printf(" 2  if serious trouble (e.g., cannot access command-line argument).\n\n");

    printf("GNU coreutils online help: <https://www.gnu.org/software/coreutils/>\n");
    printf("Full documentation <https://www.gnu.org/software/coreutils/ls>\n");
    printf("or available locally via: info '(coreutils) ls invocation'\n");
}

void versionFlag() {
    printf("ls (GNU coreutils) 9.1\n");
    printf("Copyright (C) 2022 Free Software Foundation, Inc.\n");
    printf("License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
    printf("This is free software: you are free to change and redistribute it.\n");
    printf("There is NO WARRANTY, to the extent permitted by law.\n\n");
    printf("Written by Richard M. Stallman and David MacKenzie.\n");
}