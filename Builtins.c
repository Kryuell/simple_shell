#include "shell.h"
#include <unistd.h>

/**
 * check_builtin - Check if a command is a built-in.
 * @command: The command to check.
 * Return: 1 if built-in, 0 otherwise.
 */
int check_builtin(char *command)
{
	char *builtins[] = {"exit", "env", "setenv", "cd", NULL};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (my_strcmp(command, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handle_builtin - Handle execution of built-in commands.
 * @command: The command and its arguments.
 * @argv: The program name and its arguments.
 * @status: The exit status.
 * @idex: The current index.
 */
void handle_builtin(char **command, char **argv, int *status, int idex)
{
	if (my_strcmp(command[0], "exit") == 0)
		exit_shell(command, argv, status, idex);
	else if (my_strcmp(command[0], "env") == 0)
		print_env(command, status);
}

/**
 * exit_shell - Handle the 'exit' built-in command.
 * @command: The command and its arguments.
 * @argv: The program name and its arguments.
 * @status: The exit status.
 * @idex: The current index.
 */
void exit_shell(char **command, char **argv, int *status, int idex)
{
	int exit_va = (*status);
	char *index, ermsg[] = ": exit: Illegal number: ";

	if (command[1])
	{
		if (is_positive_n(command[1]))
		{
			exit_va = _atoi(command[1]);
		}
		else
		{
			index = _itoa(idex);
			write(STDERR_FILENO, argv[0], my_strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, my_strlen(index));
			write(STDERR_FILENO, ermsg, my_strlen(ermsg));
			write(STDERR_FILENO, command[1], my_strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			freeArray(command);
			(*status) = 2;
			return;
		}
	}

	freeArray(command);
	exit(exit_va);
}

/**
 * print_env - Handle the 'env' built-in command.
 * @command: The command and its arguments.
 * @status: The exit status.
 */
void print_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], my_strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freeArray(command);
	(*status) = 0;
}
