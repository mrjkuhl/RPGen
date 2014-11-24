#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern const int MAXWORDSIZE;

const int MAXLINESIZE = 100;

int readConfigOption(char** value, char* configOption, FILE* configPointer);
#endif
