#ifndef __ERROR_H__
#define __ERROR_H__

#include <stdio.h>

int ERRORVALUE;

struct errorText {

	const char* errorText[5];
	const char* invalidArgument[2];
};

struct errorText ERRORTEXT = {
	
	.errorText[0] = "Could not write to STDOUT.",
	.errorText[1] = "Not enough options.",
	.errorText[2] = "Could not open file.",
	.errorText[3] = "Invalid argument value.",
	.errorText[4] = "Word not found.",

	.invalidArgument[0] = "rpgen: invalid option -- '",
	.invalidArgument[1] = "'\nTry 'rpgen --help' for more information."
};

void printError(int errorCode);
int invalidArgument(char* argument);

#endif
