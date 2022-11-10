#include "main.h"

/**
* main - a simple shell 
*
* Return:
*/
int main()
{
	char *lineptr = NULL;
	char **argv = NULL;
	size_t n;

	write(1, "$ ",1);
	getline(&lineptr, &n, stdin);
	argv = tokenize(lineptr);

	

	/**
	 * test to see if tokenize works
	 */
	while (*argv)
	{
		printf("%s\n", *argv);
		argv++;
	}
	return (0);
}
