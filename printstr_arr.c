#include "main.h"

/**
*printstr - prints an array of strings
*
*@str_arr: array of strings to be printed.
*/

void printstr(char **str_arr)
{
	int i = 0;
	int n;
	char str[1];

	while (str_arr[i])
	{
		n = 0;

		while (str_arr[i][n])
		{
			str[0] = str_arr[i][n];

			write(1, str, 1);
			n++;
		}
		i++;
		write(1, "\n", 1);
	}
}
