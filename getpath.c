#include "shell.h"
/**
 * _getpath - Get the full path of a command from the PATH environment var.
 * @commands: The command to search for in the PATH directories.
 *
 * Return: If the command is found, return the full path. Otherwise, NULL.
 */

char *_getpath(char *commands)
{
	char *path_env, *full_cmd, *dir;
	int i;
	struct stat st;

	for (i = 0; commands[i]; i++)
	{
		if (commands[i] == '/')
		{
			if (stat(commands, &st) == 0)
				return (my_strdup(commands));
			return (NULL);
		}
	}

	path_env = _getenv("PATH");
	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc(my_strlen(dir) + my_strlen(commands) + 2);

		if (full_cmd)
		{
			my_strcpy(full_cmd, dir);
			my_strcat(full_cmd, "/");
			my_strcat(full_cmd, commands);

			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}

			free(full_cmd);
			dir = strtok(NULL, ":");
		}
	}

	free(path_env);
	return (NULL);
}
