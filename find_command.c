#include "main.h"

/**
 * find_command - search for a command in the directoris in PATH
 * @command: the command to be searched
 * @environ: the environment
 * Return: 0 if command is found, -1 if command not found
 */
char *find_command(char *command, char **environ)
{
	int i = 0;
	char *path;
	char **tokenized_path;
	DIR *dir;
	struct dirent *read_entry;
	int status = 0;
	char *full_path;

	while (environ[i])
	{
		if (is_substring("PATH=", environ[i]))
		{
			path = _strcpy(environ[i]);
			tokenized_path = tokenize(path + 5, ":");
			break;
		}
		i++;
	}

	i = 0;
	while (tokenized_path[i] && status == 0)
	{
		dir = opendir(tokenized_path[i]);
		read_entry = readdir(dir);

		while (read_entry)
		{
			if (strcompare(command, read_entry->d_name) == 1)
			{
				full_path = _strcpy(tokenized_path[i]);
				if (full_path == NULL)
				{
					free(tokenized_path);
					return (NULL);
				}
				full_path = str_append(full_path, "/");
				if (full_path == NULL)
				{
					free(tokenized_path);
					return (NULL);
				}
				full_path = str_append(full_path, command);
				if (full_path == NULL)
				{
					free(tokenized_path);
					return (NULL);
				}
				status = 1;
				break;
			}
			read_entry = readdir(dir);
		}
		i++;
		closedir(dir);
	}


	i = 0;
	free(path);
	free(tokenized_path);

	if (status == 1)
		return (full_path);
	else
		return (NULL);
}
