#include "shell.h"




/**
 * _strdup - duplicates a string
 *
 * @str: string to be duplicated
 *
 * Return: pointer to str [head of new string]
 *
 */

char *_strdup(const char *str)
{
	char *new;
	size_t len;

	len = _strlen(str);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, str, len + 1);
	return (new);
}



/**
 * _strlen - calculates the lenght of a string.
 *
 * @str: string to be len calculated
 *
 * Return: returns len [length of the string]
 *
 */

int _strlen(const char *str)
{
	int len;

	for (len = 0; str[len] != 0; len++)
		;
	return (len);
}


int _strspn(char *s, char *accept)
{
	int i, j, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}


char *_strcpy(char *dest, char *src)
{

	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}


int _strcmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] == s2[i] && str1[i]; i++)
		;

	if (str1[i] > str2[i])
		return (1);
	if (str1[i] < str2[i])
		return (-1);
	return (0);
}



char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
