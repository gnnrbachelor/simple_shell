#include "shell.h"

/**
 * _strcmp - Compares two strings.
 *
 * @s1: String one
 * @s2: String two
 *
 * Return: Difference
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
}

/**
 * _strcpy - copies string
 *
 * @dest: copy
 * @src: original
 *
 * Return: *dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int j;

	while (src[i] != '\0')
		i++;

	for (j = 0; j < i; j++)
		dest[j] = src[j];

	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - counts length of string
 *
 * @s: String
 *
 * Return: void
 */

int _strlen(char *s)
{
	int counter = 0;

	while (*s != '\0')
	{
		counter++;
		s++;
	}
	return (counter);
}
