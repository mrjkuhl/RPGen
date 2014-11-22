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

			fseek(filePointer, 0, SEEK_SET);

			return 0;
		}
	}

	fseek(filePointer, 0, SEEK_SET);

	return 1;
}
