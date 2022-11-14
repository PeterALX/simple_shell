#include "main.h"

/**
* _strcpy - copies a string 
* @src: the string to be copied
* Return: a pointed to the copy
*/
char *_strcpy(char *src)
{
	char *copy;
	int i = 0;
	int n = 200;
	
	copy = malloc(sizeof(char) * 200);
	if (copy == NULL)
		return (copy);

	while (src[i])
	{
		if (i >= n)
		{
			n += 5;
			copy = realloc(copy, sizeof(char) * n);
		}
		
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';

	return (copy);
}
