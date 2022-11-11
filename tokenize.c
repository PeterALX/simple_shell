#include "main.h"

/**
* tokenize - takes a string and divides it into tokens
*
* Return:
*/
char **tokenize(char *str)
{
	int i;
	char **tokens;

	tokens = malloc(sizeof(char *) * 100);

	tokens[0] = strtok(str, " \n");
	i = 1;
	while ((tokens[i] = strtok(NULL, " \n")))
		i++;

	return tokens;
}
