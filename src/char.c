#include "char.h"

int stripString(char** string) {

	char* tmp = *string;
	int lastChar = strlen(tmp) - 1;

	if (tmp[lastChar] == '\n' || tmp[lastChar] == EOF) {

		tmp[lastChar] = '\0';
	}

	*string = tmp;

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
