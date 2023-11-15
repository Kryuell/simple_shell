#include "shell.h"
#include <stdio.h>

/**
 * main - Entry point for the custom shell program.
 * @ac: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: Returns the exit status of the shell program.
 */

int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, commandIndex = 0;
	(void)ac;  /* Silence unused parameter warning */

	while (1) /* Infinite loop for shell functionality */
	{
		line = readLine();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		commandIndex++;
		command = parser(line);
		if (!command)
			continue;

		if (check_builtin(command[0]))
			handle_builtin(command, argv, &status, commandIndex);
		else
			status = my_execute(command, argv, commandIndex);
	}

	return (0); /* Ensure a return statement at the end of the main function */
}
