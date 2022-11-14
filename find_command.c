#include "main.h"

/**
* find_command - search for a command in the directoris in PATH
* @command: the command to be searched
* @environ: the environment
* Return: 0 if command is found, -1 if command not found
*/
int find_command(char *command, char **environ)
{
	int i = 0;
	char *path;
	char **tokenized_path;


	while (environ[i])
	{
		if (is_substring("PATH=", environ[i]))
		{
			path = _strcpy(environ[i]);
			printf("path copied:%s\n", path);
			tokenized_path = tokenize(path + 5 , ":");
			break;

		}
		i++;
	}

	i = 0;
	while (tokenized_path[i])
	{
		printf("%s\n", tokenized_path[i]);
		i++;
	}


}
