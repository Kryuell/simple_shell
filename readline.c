#include "shell.h"

/**
 * readLine - Reads a line from the standard input.
 *
 * Return: A pointer to the read line.
 */
char *readLine(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t index;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	index = getline(&line, &len, stdin);

	if (index == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
