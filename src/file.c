#include "file.h"

int openFile(FILE** filePointer, char* fileName) {

	*filePointer = fopen(fileName, "r");

	if (filePointer == NULL) {

		printError(1);

		return 1;
	}

	return 0;
}

int getLineCount(FILE* filePointer) {

	int count = 0;
	char line[(MAXWORDSIZE + 1)];

	while (fgets(line, sizeof(line), filePointer)) {

		count++;
	}

	fseek(filePointer, 0, SEEK_SET);

	return count;
}

int getLineNumber(char** line, int lineNumber, FILE* filePointer) {

	int count = 0;
	int lineLength;
	*line = (char*)calloc(MAXWORDSIZE + 1, sizeof(char));

	while (fgets(*line, MAXWORDSIZE, filePointer)) {

		if (++count == lineNumber) {

			break;
		}
	}

	stripString(*line);

	fseek(filePointer, 0, SEEK_SET);

	return 0;
}
