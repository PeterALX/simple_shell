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
	int c = 1;


	while (c != 0)
	{
		write(1, "$ ",2);
		getline(&lineptr, &n, stdin);
		argv = tokenize(lineptr, " \n");

		if (strcompare(argv[0], "exit") == 1)
			break;

		if (strcompare(argv[0], "env") == 1)
		{	
			printstr(environ);
			continue;
		}

		if (is_substring("/", argv[0]) || is_substring("./", argv[0]))
		{
			printf("do not use path!\n");
		}
		else
		{
			printf("use path\n");
			find_command(argv[0], environ);
		}


		if (fork() == 0)
		{
			execve(argv[0], argv, environ);
			printf("No such file or directory\n");
		}
		else
			wait(NULL);
	}

	return (0);
}
