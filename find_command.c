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
	DIR *dir;
	struct dirent *read_entry;
	int status = 0;


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
	printf ("Command: %s\n", command);

	i = 0;
	while (tokenized_path[i] && status == 0)
	{
		dir = opendir(tokenized_path[i]);
		read_entry = readdir(dir);

		while (read_entry)
		{
			if (strcompare(command, read_entry->d_name) == 1)
			{
				printf ("Match found\n");
				status = 1;
				break;
			}
			read_entry = readdir(dir);
		}
		i++;
		closedir(dir);
	}
	return (0);
}
