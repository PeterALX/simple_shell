#include "main.h"

/**
* tokenize - takes a string and divides it into tokens
*
* Return:
*/
char **tokenize(char *str, char *delimiter)
{
	int i;
	char **tokens;

	tokens = malloc(sizeof(char *) * 100);

	tokens[0] = strtok(str, delimiter);
	i = 1;
	while ((tokens[i] = strtok(NULL, delimiter)))
		i++;

	return tokens;
}
