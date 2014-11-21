#ifndef __FILE_H__
#define __FILE_H__

#include <stdio.h>

extern const int MAXWORDSIZE;

int openFile(FILE** filePointer, char* fileName);
int getLineCount(FILE *filePointer);

#endif
