#include "main.h"

/**
* main - a simple shell
*
* Return: always 0
*/
int main(void)
{
	char *lineptr = NULL;
	size_t n;
	int c = 0;
	int number;

	if (isatty(0) == 0)
	{
		number = getline(&lineptr, &n, stdin);
		while (lineptr[number - 1] == '\n')
		{
			execute(lineptr);
			number = getline(&lineptr, &n, stdin);
		}
		free(lineptr);
		return (0);
	}
	while (c == 0)
	{
		write(1, "$ ", 2);
		getline(&lineptr, &n, stdin);
		c = execute(lineptr);

	}

	free(lineptr);
	return (0);
}
int execute(char *lineptr)
{
	char **argv;
	char *full_path;

	argv = tokenize(lineptr, " \n");
	if (*argv == NULL)
		return (0);
	/* check for built ins */
	if (strcompare(argv[0], "exit") == 1)
	{
		free(argv);
		return (1);
	}
	if (strcompare(argv[0], "env") == 1)
	{
		printstr(environ);
		free(argv);
		return (0);
	}

	/* check whether to use command finder*/
	if (is_substring("/", argv[0]) || is_substring("./", argv[0]))
	{
		if (fork() == 0)
		{
			execve(argv[0], argv, environ);
			printf("No such file or directory\n");
			free(argv);
			return (0);
		}
		else
			wait(NULL);
	}
	else
	{
		full_path = find_command(argv[0], environ);
		if (full_path)
		{
			if (fork() == 0)
			{
				execve(full_path, argv, environ);
				printf("something wrong while executing %s\n", full_path);
				free(argv);
				return (0);
			}
			else
			{
				wait(NULL);
			}

		}
		else
			printf("No such file or directory\n");
	}

	free(argv);
	free(full_path);
	return (0);

}
