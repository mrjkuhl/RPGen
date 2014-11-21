#include "config.h"

int readConfigOption(char** optionValue, char* configOption, FILE* configPointer) {

	int i;
	char line[MAXWORDSIZE + 1];

	while (fgets(line, sizeof(line), configPointer)) {

		if(strstr(line, configOption) != NULL) {

			strcpy(*optionValue, line + strlen(configOption) + 1);

			return 0;
		}
	}

	return 1;
}
