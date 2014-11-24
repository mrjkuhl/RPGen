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

#include "config.h"

int readConfigOption(char** optionValue, char* configOption, FILE* configPointer) {

	int i;
	char line[MAXLINESIZE];
	char* value = (char*)calloc(MAXWORDSIZE + 1, sizeof(char));

	while (fgets(line, sizeof(line), configPointer)) {

		if(strstr(line, configOption) != NULL) {

			line[strlen(line) - 1] = '\0';
			strcpy(value, line + strlen(configOption) + 1);

			*optionValue = value;

			fseek(configPointer, 0, SEEK_SET);

			return 0;
		}
	}

	fseek(configPointer, 0, SEEK_SET);

	printError(1);

	return 1;
}
