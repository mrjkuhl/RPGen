/*
 * Copyright 2014 Joel Cool-Panama <mr.jkuhl@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
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

#include "main.h"
#include "generate.h"

int main(int argc, char *argv[]) {

	char* randomDevice = "";
	char* dictionary = "";
	char* password;

	int passwordLength = 0;
	int modeType = 0;
	int i;

	for (i = 1; i < argc; i ++) {

		if (strcmp(argv[i], "-m") == 0 || strcmp(argv[i], "--mode") == 0) {

			if (strcmp(argv[(i + 1)], "random") == 0) {

				modeType = 1;
			}

			else if (strcmp(argv[(i + 1)], "dictionary") == 0) {

				modeType = 2;
			}
		}

		else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--length") == 0) {

			passwordLength = atoi(argv[(i + 1)]);
		}

		else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--dictionary") == 0) {

			dictionary = argv[(i + 1)];
		}

		else if (strcmp(argv[i], "-D") == 0 || strcmp(argv[i], "--device") == 0) {

			randomDevice = argv[(i + 1)];
		}
	}

	if (randomDevice[0] == '\0') {

		randomDevice = "/dev/urandom";
	}

	if (passwordLength < 0) {

		printError(2);
	}

	if (modeType == 1 || modeType == 0) {

		if (passwordLength == 0) {

			passwordLength = 16;
		}

		if(generateRandomPassword(&password, passwordLength, randomDevice) != 0) {

			printError(2);
			return 2;
		}
	}

	else if (modeType == 2) {

		if (passwordLength == 0) {

			passwordLength = 4;
		}

		if (dictionary[0] == '\0') {

			dictionary = "dictionary";
		}

		if(generateDictionaryPassword(&password, passwordLength, dictionary, randomDevice) != 0) {

			printError(2);
			return 2;
		}
	}

	else {

		printError(1);

		return 1;
	}

	fprintf(stdout, "Password: %s\n", password);

	free(password);

	if (ferror(stdout)) {

		printError(2);
	}

	return 0;
}

char* getDictionaryWord(int wordNumber, FILE *dictionaryPointer) {

	int count = 0;
	int wordLength;
	char* word = (char*)calloc(MAXWORDSIZE, sizeof(char));

	while (fgets(word, MAXWORDSIZE, dictionaryPointer)) {

		if (++count == wordNumber) {

			break;
		}
	}

	wordLength = strlen(word) - 1;

	if (word[wordLength] == '\n') {

		word[wordLength] = '\0';
	}

	fseek(dictionaryPointer, 0, SEEK_SET);

	return word;
}

int getLineCount(FILE *filePointer) {

	int count = 0;
	char line[(MAXWORDSIZE + 1)];

	while (fgets(line, sizeof(line), filePointer)) {

		count++;
	}

	fseek(filePointer, 0, SEEK_SET);

	return count;
}

unsigned long int sumString(char* string) {

	int i;
	int stringLength = strlen(string);
	unsigned long int stringSum = 0;

	for (i = 0; i < stringLength; i++) {

		stringSum += string[i];
	}

	return stringSum;
}

void printError(int errorCode) {

	fprintf(stdout, "kek, %d\n", errorCode);

	return;
}

