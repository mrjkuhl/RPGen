#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXWORDSIZE = 45;

char* getDictionaryWord(int wordNumber, FILE* dictionaryPointer);
unsigned long int sumString(char* string);

#endif
