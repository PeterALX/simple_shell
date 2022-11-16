#include "main.h"

/**
* main - a simple shell
*
* Return: always 0
*/
int main(void)
{
	char *lineptr = NULL;
	char **argv;
	char *full_path;
	size_t n;
	/*int c = 1;*/


	while (1)
	{
		write(1, "$ ", 2);
		getline(&lineptr, &n, stdin);
		argv = tokenize(lineptr, " \n");

		/* check for built ins */
		if (strcompare(argv[0], "exit") == 1)
			break;
		if (strcompare(argv[0], "env") == 1)
		{
			printstr(environ);
			continue;
		}

		/* check whether to use command finder*/
		if (is_substring("/", argv[0]) || is_substring("./", argv[0]))
		{
			if (fork() == 0)
			{
				execve(argv[0], argv, environ);
				printf("No such file or directory\n");
				break;
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
					break;
				}
				else
				{
					free(full_path);
					wait(NULL);
				}

			}
			else
				printf("No such file or directory\n");
		}


	}

	return (0);
}
