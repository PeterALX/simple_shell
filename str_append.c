#include "main.h"

/**
* str_append - appends substr to dest
* @dest: the string to be appended to
* @substr: the string to append
* Return: a pointer to the new appended string
*/
char *str_append(char *dest, char *substr)
{
	int i = 0;
	int n = 0;/*used to find the length of substr*/
	int d = 0; /*used to iterate through substr when appending*/
	char *appended_str;

	while (dest[i])
		i++;
	while (substr[n])
		n++;

	appended_str = realloc(dest, sizeof(char) * (i + n) + 1);
	if (appended_str == NULL)
		return (NULL);

	while (substr[d])
	{
		appended_str[i + d] = substr[d];
		d++;
	}
	appended_str[i + d] = '\0';

	return (appended_str);
}
