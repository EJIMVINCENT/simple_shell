#include "shell.h"

/**
 * readLine - reads the input string.
 *
 * @check: return value of getline function
 *
 * Return: input (string from user)
 *
 */

char *readLine(int *check)
{
	char *input = NULL;
	size_t buffsize = 0;

	*check = getline(&input, &buffsize, stdin);

	return (input);
}


/**
 * remComment - removes comment from input
 *
 * @input: input string
 *
 * Return: returns input with comments removed
 *
 */

char *remComment(char *input)
{
	int i, index;

	index = 0;

	for (i = 0; input[i]; i++)
	{
		if (input[i] == '#')
		{
			if (i == 0)
			{
				free(input);
				return (NULL);
			}
			if (input[i - 1] == ' ' || input[i - 1]
			    == '\t' || input[i - 1] == ';')
				index = i;
		}
	}

	if (index != 0)
	{
		input = _realloc(input, i, index + 1);
		input[index] = '\0';
	}
	return (input);
}
