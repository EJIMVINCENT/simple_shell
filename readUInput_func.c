#include "shell.h"

/**
 * read_line - reads the input string.
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
 * _getline - custome getline function (reads input from
 * stdin)
 *
 * @input: destination to store characters read
 * @n: size of characters to read from stdin
 * @inputStream: inputStream to read from (stdin)
 *
 * return: returns the number of character read
 *
 */ 


int _getline(char **input, size_t *n, FILE *inputStream)
{
	ssize_t temp;
	int status;
	static ssize_t count;
	char character = 'a';
	char *buffer;

	if (count == 0)
		fflush(inputStream);

	else
		return (-1);
	count = 0;

	buffer = malloc(sizeof(char) * BUFFERSIZE);;
	if (buffer == NULL)
		return (-1);

	while (character != '\n')
	{
		status = read(STDIN_FILENO, &character, 1);
		/*check for error and eof*/ 
		if (status == -1 || (status = 0 && count == 0))
		{
			free(buffer);
			return (-1);
		}
		if (status == 0 && count != 0)
		{
			count++;
			break;
		}
		if (count >=  BUFFERSIZE)
			buffer = _realloc(buffer, count, count + 1);
		buffer[count] = character;
		count++;
	}

	buffer[count] = '\0';
	*input = buffer;
	*n = count;
	temp = count;
	if (status != 0)
		count = 0;
	return (temp);
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
