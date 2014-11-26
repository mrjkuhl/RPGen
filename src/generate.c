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

#include "generate.h"

int generateRandomPassword(char** password, int passwordLength, char* randomDevice) {

	int i;

	FILE* devicePointer;
	char* character = (char*)calloc(2, sizeof(char));

	*password = (char*)calloc(passwordLength + 1, sizeof(char));

	if (openFile(&devicePointer, randomDevice) != 0) {

		return ERRORVALUE;
	}

	for (i = 0; i < passwordLength; i++) {

		fscanf(devicePointer, "%c", &character[0]);

		character[0] = (abs(character[0]) % 95) + 32;
		strcat(*password, character);
	}

	fclose(devicePointer);
	free(character);

	return 0;
}

int generateDictionaryPassword(char** password, int passwordLength, char* dictionary, char* randomDevice) {

	int i;
	int lineCount;

	FILE* devicePointer;
	FILE* dictionaryPointer;
	char* word;
	char* seed = (char*)calloc(101, sizeof(char));

	*password = (char*)calloc(passwordLength * MAXWORDSIZE + 1, sizeof(char));

	if (openFile(&devicePointer, randomDevice) != 0) {

		return ERRORVALUE;
	}

	if (openFile(&dictionaryPointer, dictionary) != 0) {

		return ERRORVALUE;
	}

	fread(seed, sizeof(char), 100, devicePointer);

	srand(sumString(seed));
	free(seed);

	lineCount = getLineCount(dictionaryPointer);

	for (i = 0; i < passwordLength; i++) {

		getLineNumber(&word, (rand() % lineCount), dictionaryPointer);
		strcat(*password, word);
		free(word);
	}

	fclose(devicePointer);
	fclose(dictionaryPointer);

	return 0;
}
