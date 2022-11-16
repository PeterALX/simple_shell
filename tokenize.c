#include "main.h"

/**
* tokenize - takes a string and divides it into tokens
* @str: the string to be tokenized
* @delimiter: the delimiter to use in tokenizing
* Return: a pointer to the tokens
*/
char **tokenize(char *str, char *delimiter)
{
	int i;
	char **tokens;

	tokens = malloc(sizeof(char *) * 100);
	if (tokens == NULL)
		return (NULL);
	tokens[0] = strtok(str, delimiter);
	i = 1;
	while ((tokens[i] = strtok(NULL, delimiter)))
		i++;

	return (tokens);
}
