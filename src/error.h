#ifndef __ERROR_H__
#define __ERROR_H__

#include <stdio.h>

const char* INVALIDARGUMENT[2] = {"rpgen: invalid option -- '", "'\nTry 'rpgen --help' for more information."};

void printError(int errorCode);
int invalidArgument(char* argument);

#endif
