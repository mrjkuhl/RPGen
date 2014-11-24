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

#include "char.h"

int stripString(char* string) {

	int lastChar = strlen(string) - 1;

	if (string[lastChar] == '\n' || string[lastChar] == EOF) {

		string[lastChar] = '\0';
	}

	return 0;
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
