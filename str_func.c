#include "shell.h"

/**
 * _strlen - calculates the lenght of a string
 *
 * @string: string to be counted
 *
 * Return: returns (i) lenght of the string
 *
 */

int _strlen(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
		;
	return (i);
}


/**
 * _strcmp - compares two strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: returns 0 if strings are equal
 * & a positive number is s1 comes first else negative
 *
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, j;

	while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
		i++;

	if (s1[i] == s2[i])
		return (0);

	else
	{
		j = s1[i] - s2[i];
		return (j);
	}
}


/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 *
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len;
	int  i;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}
	len++;

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}

/**
 * _strcat - concatenates two strings
 *
 * @dest: first string
 * @src: second string
 *
 * Return: returns dest
 *
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	dest[i + j + 1] = '\0';

	return (dest);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 *
 * @str: pointer to the string
 *
 * Return: returns copy
 *
 */

char *_strdup(char *str)
{
	int i;
	int size = 1;
	char *copy;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
		size++;

	copy = (char *) malloc(sizeof(char) * size);

	if (!copy)
		return (0);

	for (i = 0; i <= size; i++)
		copy[i] = str[i];

	return (copy);
}
