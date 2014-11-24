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

#include "main.h"

int main(int argc, char *argv[]) {

	FILE* configPointer;

	char* randomDevice = "";
	char* dictionary = "";
	char* modeType = "";
	char* tmp = "";
	char* password;

	int passwordLength = 0;
	int i;

	for (i = 1; i < argc; i ++) {

		if (strcmp(argv[i], "-m") == 0 || strcmp(argv[i], "--mode") == 0) {

			modeType = argv[(i + 1)];
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

	if (openFile(&configPointer, "/etc/rpgen/rpgen.conf") != 0) {

		printError(1);
		return 1;
	}

	if (randomDevice[0] == '\0' && readConfigOption(&randomDevice, "DEFAULTRNGDEVICE", configPointer) != 0) {

		printError(1);
		return 1;
	}

	if (modeType[0] == '\0' && readConfigOption(&tmp, "DEFAULTPASSWORDMODE", configPointer) != 0) {

		printError(1);
		return 1;
	}

	else if (modeType[0] == '\0') {

		modeType = tmp;
	}

	if (passwordLength < 0) {

		printError(2);
	}

	if (strcmp(modeType, "random") == 0) {

		if (strcmp(modeType, tmp) == 0) {

			free(tmp);
		}

		if (passwordLength == 0 && readConfigOption(&tmp, "DEFAULTPASSWORDLENGTHRANDOM", configPointer) != 0) {

			printError(1);
			return 1;
		}

		if (tmp[0] != '\0') {

			passwordLength = atoi(tmp);
			free(tmp);
		}

		if(generateRandomPassword(&password, passwordLength, randomDevice) != 0) {

			printError(2);
			return 2;
		}
	}

	else if (strcmp(modeType, "dictionary") == 0) {

		if (strcmp(modeType, tmp) == 0) {

			free(tmp);
		}

		if (passwordLength == 0 && readConfigOption(&tmp, "DEFAULTPASSWORDLENGTHDICTIONARY", configPointer) != 0) {

			printError(1);
			return 1;
		}

		if (tmp[0] != '\0') {

			passwordLength = atoi(tmp);
			free(tmp);
		}

		if (dictionary[0] == '\0' && readConfigOption(&tmp, "DEFAULTDICTIONARY", configPointer) != 0) {

			printError(1);
			return 1;
		}

		else if (dictionary[0] == '\0') {

			dictionary = tmp;
		}

		if(generateDictionaryPassword(&password, passwordLength, dictionary, randomDevice) != 0) {

			printError(2);
			return 2;
		}

		if (strcmp(dictionary, tmp) == 0) {

			free(tmp);
		}
	}

	else {

		printError(1);

		return 1;
	}

	fprintf(stdout, "Password: %s\n", password);

	if (ferror(stdout)) {

		printError(2);
	}

	fclose(configPointer);

	free(randomDevice);
	free(password);

	return 0;
}
