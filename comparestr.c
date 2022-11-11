#include "main.h"

/**
*strcompare - Compares strings 
*@str1: string 1 
*@str2: string 2
*Return: 0 if success, 1 if not success
*/

int strcompare(char *str1, char *str2)
{
	int n = 0;

	while (str1[n] && str2[n])
	{
		if (str1[n] != str2[n])
			return (0);
		n++;
	}
	
	if (str1[n] != '\0' || str2[n] != '\0')
		return (0);
	
	return (1);
}
