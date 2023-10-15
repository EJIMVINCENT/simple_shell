#include "shell.h"


/**
 * stringCmp - compares two strings
 * @str: pointer to a char
 * @delim: pointer to a char
 *
 * Return: 0
 */
int stringCmp(char *str, const char *delim)
{
	unsigned int i, j, k = 0;

	for (i = 0; str[i]; i++)
	{
		j = 0;
		while (delim[j])
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
			j++;
		}
	}
	if (i == k)
		return (1);
	return (0);
}


/**
 * _strtok - tokenize a string
 * @string: pointer to a char
 * @delim: pointer to a char
 *
 * Return: a pointer to the next token or NULL if non
 */
char *_strtok(char *string, const char *delim)
{
	static char *temp, *strEnd;
	char *strStart;
	unsigned int i, status;

	if (string != NULL)
	{
		if (stringCmp(string, delim))
			return (NULL);
		temp = string;
		i = _strlen(string);
		strEnd = &string[i];
	}
	strStart = temp;
	if (strStart == strEnd)
		return (NULL);

	for (status = 0; *temp; temp++)
	{
		if (temp != strStart)
			if (*temp && *(temp - 1) == '\0')
				break;
		for (i = 0; delim[i]; i++)
		{
			if (*temp == delim[i])
			{
				*temp = '\0';
				if (temp == strStart)
					strStart++;
				break;
			}
		}
		if (status == 0 && *temp)
			status = 1;
	}
	if (status == 0)
		return (NULL);
	return (strStart);
}


/**
 * _strcat - concatenate strings
 * @dest: A pointer to the destination string
 * @src: A pointer to the source string
 *
 * Return: value of dest
 */
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
