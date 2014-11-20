#ifndef __GENERATE_H__
#define __GENERATE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern const int MAXWORDSIZE;

int generateRandomPassword(char** password, int passwordLength, char* randomDevice);
int generateDictionaryPassword(char** password, int passwordLength, char* dictionary, char* randomDevice);

#endif
