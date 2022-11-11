#include "main.h"

/**
* main - a simple shell 
*
* Return:
*/
int main()
{
	char *lineptr = NULL;
	char **argv;
	size_t n;
	int error;


	write(1, "$ ",2);
	getline(&lineptr, &n, stdin);
	argv = tokenize(lineptr);

	error = execve(argv[0], argv, environ);
	
	printf("%d\n", error);

	/**
	 * test to see if tokenize works
	 */
	while (*argv)
	{
		printf("%s:\n ", *argv);
		argv++;
	}
	return (0);
}
