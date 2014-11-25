#ifndef __INFO_H__
#define __INFO_H__

#include <stdio.h>

const char* VERSIONINFO = "RPGen 0.2\n"
"Copyright 2014 Joel Cool-Panama <mr.jkuhl@gmail.com>\n"
"License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\n"
"This is free software: you are free to change and redistribute it.\n"
"There is NO WARRANTY, to the extent permitted by law.";

const char* HELPINFO = "Usage: rpgen [OPTION]...\n"
"Generate a random password, to standard output.\n"
"\n"
"  -l, --length		number of characters or words\n"
"  -m, --mode		type of password\n"
"  -d, --dictionary	dictionary to use\n"
"  -D, --device		file to seed random generator with\n"
"      --help		display this help and exit\n"
"      --version		output version information and exit";

int printVersion();
int printHelp();

#endif
