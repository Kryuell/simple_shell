#include "shell.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * freeArray - Frees the memory allocated for a dynamic array of strings.
 * @arr: The array of strings to be freed.
 */
void freeArray(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
		free(arr[i]), arr[i] = NULL;

	free(arr), arr = NULL;
}

/**
 * print_error - Prints an error message to standard error.
 * @name: The program name.
 * @cmd: The command that caused the error.
 * @idex: The index of the error.
 */
void print_error(char *name, char *cmd, int idex)
{
	char *index, mssg[] = ": not found\n";

	index = _itoa(idex);

	write(STDERR_FILENO, name, my_strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, my_strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, my_strlen(cmd));
	write(STDERR_FILENO, mssg, my_strlen(mssg));

	free(index);
}

/**
 * _itoa - Converts an integer to a string.
 * @n: The integer to be converted.
 * Return: A dynamically allocated string representation of the integer.
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';

	rev_string(buffer, i);

	return (my_strdup(buffer));
}

/**
 * rev_string - Reverses a string in place.
 * @str: The string to be reversed.
 * @len: The length of the string.
 */
void rev_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
