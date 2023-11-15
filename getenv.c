#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
/**
 * _getenv - Get the value of an environment variable.
 * @variable: The name of the environment variable to retrieve.
 *
 * Return: If the variable is found, return its value. Otherwise, return NULL.
 */
char *_getenv(char *variable)
{
	char *temp, *key, *value, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		temp = my_strdup(environ[i]);
		key = strtok(temp, "=");

		if (strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = my_strdup(value);
			free(temp);
			return (env);
		}

		free(temp);
		temp = NULL;
	}

	return (NULL);
}
