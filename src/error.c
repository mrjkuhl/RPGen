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

#include "error.h"

void printError(int errorCode) {

	ERRORVALUE=errorCode;

	fprintf(stdout, "Error: %s\nExiting...\n", ERRORTEXT.errorText[--errorCode]);

	return;
}

int invalidArgument(char* argument) {

	fprintf(stdout, "%s%s%s\n", ERRORTEXT.invalidArgument[0], argument, ERRORTEXT.invalidArgument[1]);

	if (ferror(stdout) == 0) {

		return 0;
	}

	printError(1);
	return ERRORVALUE;
}
