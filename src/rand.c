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
