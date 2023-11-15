#include "shell.h"

/**
 * my_execute - Execute a command using fork and execve
 * @command: An array of strings representing the command and its arguments
 * @argv: An array of strings representing the arguments to the program
 * @idex: An integer representing the index
 *
 * Return: The exit status of the executed command
 */
int my_execute(char **command, char **argv, int idex)
{
	char *full_cmd;
	pid_t child_pid;
	int status;

	full_cmd = _getpath(command[0]);

	if (!full_cmd)
	{
		print_error(argv[0], command[0], idex);
		freeArray(command);
		return (127);
	}

	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			free(full_cmd);
			freeArray(command);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		freeArray(command);
		free(full_cmd);
	}

	return (WEXITSTATUS(status));
}
