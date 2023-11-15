#include "shell.h"

/**
 * parser - Tokenizes the input line into an array of strings.
 * @line: The input string to be tokenized.
 *
 * Return: An array of strings containing the tokens.
 *         Returns NULL if there was an error or if the input line is empty.
 */

char **parser(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int cpt = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = my_strdup(line);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(line);
		line = NULL;
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		cpt++;
		token = strtok(NULL, DELIM);
	}
	free(tmp);
	tmp = NULL;
	command = malloc(sizeof(char *) * (cpt + 1));
	if (!command)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	token = strtok(line, DELIM);
	while (token)
	{
		command[i] = strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line);
	line = NULL;
	command[i] = NULL;
	return (command);    }
