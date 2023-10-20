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
	static char *t, *strEnd;
	char *strStart;
	unsigned int i, status;

	if (string != NULL)
	{
		if (stringCmp(string, delim))
			return (NULL);
		t = string;
		i = _strlen(string);
		strEnd = &string[i];
	}
	strStart = t;
	if (strStart == strEnd)
		return (NULL);

	for (status = 0; *t; t++)
	{
		if (t != strStart)
			if (*t && *(t - 1) == '\0')
				break;
		for (i = 0; delim[i]; i++)
		{
			if (*t == delim[i])
			{
				*t = '\0';
				if (t == strStart)
					strStart++;
				break;
			}
		}
		if (status == 0 && *t)
			status = 1;
	}
	if (status == 0)
		return (NULL);
	return (strStart);
}


/**
 * _strcat - concatenate strings
 *
 * @dest: A pointer to the destination string
 * @src: A pointer to the source string
 *
 * Return: value of dest
 *
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


/**
 * _isdigit - checks if input string contains only digits
 *
 * @s: input string
 *
 * Return: 1 if string contans only digits, 0 otherwise.
 *
 */

int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}

/**
 * strRev - revers an input string
 *
 * @input: input string to be reversed
 *
 * Return: no return
 *
 */

void strRev(char *input)
{
	int n, i, j;
	char *str, t;

	for (n = 0; input[n]; n++)
		;
	str = input;

	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			t = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = t;
		}
	}
}
