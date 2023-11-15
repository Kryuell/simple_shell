#include "shell.h"

/**
 * is_positive_n - Checks if a string represents a positive number.
 * @str: The input string.
 *
 * Return: The length of the string if it is a positive number, otherwise 0.
 */
int is_positive_n(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (i);
}

/**
 * _atoi - Converts a string to an integer.
 * @str: The input string.
 *
 * Return: The converted integer.
 */
int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}

	return (num);
}
