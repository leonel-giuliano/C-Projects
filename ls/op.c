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
}

void versionFlag() {
    printf("ls (GNU coreutils) 9.1\n");
    printf("Copyright (C) 2022 Free Software Foundation, Inc.\n");
    printf("License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
    printf("This is free software: you are free to change and redistribute it.\n");
    printf("There is NO WARRANTY, to the extent permitted by law.\n\n");
    printf("Written by Richard M. Stallman and David MacKenzie.\n");
}