#include "strings.h"
#include <stdlib.h>

/**
 * my_strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the source string
 *
 * Return: returns a pointer to the duplicated string.
 * It returns NULL if insufficient memory was available
 */

char *my_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		ptr[i] = str[i];

	ptr[len] = '\0';
	return (ptr);
}

/**
 * my_strcmp - Compares two strings.
 *
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: Returns the difference between the ASCII values
 *         of the first non-matching characters in the strings.
 */

int my_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return ((int)(*s1) - (int)(*s2));
}

/**
 * my_strlen - Computes the length of a string.
 *
 * @s: Input string.
 *
 * Return: Returns the length of the string.
 */

int my_strlen(const char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * my_strcat - Concatenates two strings.
 *
 * @dest: Destination string.
 * @src: Source string to concatenate.
 *
 * Return: Returns a pointer to the resulting string dest.
 */

char *my_strcat(char *dest, const char *src)
{
	char *d = dest;

	while (*d != '\0')
		d++;

	while (*src != '\0')
	{
		*d = *src;
		d++;
		src++;
	}

	*d = '\0';
	return (dest);
}

/**
 * my_strcpy - Copies a string.
 *
 * @dest: Destination string.
 * @src: Source string to copy.
 *
 * Return: Returns a pointer to the resulting string dest.
 */

char *my_strcpy(char *dest, const char *src)
{
	char *d = dest;

	while (*src)
	{
		*d = *src;
		d++;
		src++;
	}

	*d = '\0';
	return (dest);
}
