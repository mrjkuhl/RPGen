/*
 * Copyright 2014 Joel Cool-Panama <mr.jkuhl@gmail.com>
 *
 * This file is part of RPGen.
 *
 * RPGen is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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

		if (count++ == lineNumber) {

			stripString(*line);

			fseek(filePointer, 0, SEEK_SET);

			return 0;
		}
	}

	fseek(filePointer, 0, SEEK_SET);

	printError(1);

	return 1;
}
