#include "main.h"

/**
* main - a simple shell 
*
* Return:
*/
int main()
{
	char *lineptr = NULL;
	size_t n;

	write(1,"$ ",1);
	getline(&lineptr, &n, stdin);

	printf("%s\n", lineptr);
	return (0);
}
