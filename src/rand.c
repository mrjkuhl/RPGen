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

#include "rand.h"

int seedRand(FILE* devicePointer) {

	char* seed = (char*)calloc(1025, sizeof(char));

	fread(seed, sizeof(char), 1024, devicePointer);

	if (ferror(devicePointer) != 0) {

		printError(2);
		return ERRORVALUE;
	}

	srand(sumString(seed));

	free(seed);

	return 0;
}
