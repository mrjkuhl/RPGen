#include "generate.h"

int generateRandomPassword(char** password, int passwordLength, char* randomDevice) {

	int i;

	FILE *devicePointer;
	char* character = (char*)calloc(2, sizeof(char));

	*password = (char*)calloc(passwordLength + 1, sizeof(char));

	devicePointer = fopen(randomDevice, "r");

	if (devicePointer == NULL) {

		fprintf(stdout, "Random device \"%s\" could not be opened.\n", randomDevice);

		return 1;
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

	FILE *devicePointer;
	FILE *dictionaryPointer;
	char* word;
	char* seed = (char*)calloc(101, sizeof(char));

	*password = (char*)calloc(passwordLength * MAXWORDSIZE + 1, sizeof(char));

	devicePointer = fopen(randomDevice, "r");

	if (devicePointer == NULL) {

		fprintf(stdout, "Random device \"%s\" could not be opened.\n", randomDevice);

		return 1;
	}

	dictionaryPointer = fopen(dictionary, "r");

	if (dictionaryPointer == NULL) {

		fprintf(stdout, "Dictionary \"%s\" could not be opened.\n", dictionary);

		return 2;
	}

	fread(seed, sizeof(char), 100, devicePointer);

	srand(sumString(seed));
	free(seed);

	lineCount = getLineCount(dictionaryPointer);

	for (i = 0; i < passwordLength; i++) {

		word = getDictionaryWord((rand() % lineCount), dictionaryPointer);
		strcat(*password, word);
		free(word);
	}

	fclose(devicePointer);
	fclose(dictionaryPointer);

	return 0;
}


