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
