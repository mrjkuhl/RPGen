#ifndef __FILE_H__
#define __FILE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern const int MAXWORDSIZE;
extern int ERRORVALUE;

int openFile(FILE** filePointer, char* fileName);
int getLineCount(FILE* filePointer);
int getLineNumber(char** line, int lineNumber, FILE* filePointer);

#endif
