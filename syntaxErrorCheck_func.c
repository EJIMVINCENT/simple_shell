#include "shell.h"











int syntaxErrorCheck(char *input, shellData *shellD)
{
	int begin = 0, firstChar = 0, i = 0;

	firstChar = findFirst(input, &begin);

	if (firstChar  == -1)
	{
		printSError(shellD, input, begin, 0);
		return (1);
	}

	i = sepErrorCheck(input + begin, 0, *(input + begin));
	if (i != 0)
	{
		printSError(shellD, input, begin + i, 1);
		return (1);
	}
	return (0);
	
}


void printSError(shellData *shellD, char *input, int b, int x)
{
	char *m1, *m2, *m3, *error, *count;
	int len;

	if (input[b] == ';')
	{
		if (x == 0)
			m1 = (input[b + 1] == ';' ? ";;" : ";");
		else
			m1 = (input[b - 1] == ';' ? ";;" : ";");
	}

	else if (input[b] == '|')
		m1 = (input[b + 1] == '|' ? "||" : "|");
	else
		m1 = (input[b + 1] == '&' ? "&&" : "&");

	m2 = ": Syntax error: \"";
	m3 = "\" unexpected\n";
	count = _itoa(shellD->count);
	len = _strlen(shellD->argv[0]) + _strlen(count) + _strlen(m1) + _strlen(m2) + _strlen(m3) + 2;

	error = malloc(sizeof(char) * (len + 1));
	if (error == NULL)
	{
		free(count);
		return;
	}
	_strcpy(error, shellD->argv[0]);
	_strcat(error, ": ");
	_strcat(error, count);
	_strcat(error, m2);
	_strcat(error, m1);
	_strcat(error, m3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, len);
	free(error);
	free(count);
}



int countRepeat(char *input, int count)
{
	if (*(input - 1) == *input)
		return (countRepeat(input - 1, count + 1));

	return (count);
}


int sepErrorCheck(char *input, int index, char prev)
{
	int count = 0;

	if (*input == '\0')
		return (0);
	if (*input == ' ' || *input == '\t')
		return (sepErrorCheck(input + 1, index + 1, prev));
	if (*input == ';')
		if (prev == '|' || prev == '&' || prev == ';')
			return (index);
	if (*input == '|')
	{
		if (prev == ';' || prev == '&')
			return (index);
		if (prev == '|')
		{
			count = countRepeat(input, 0);
			if (count == 0 || count > 1)
				return (index);
	       	}
	}
	if (*input == '&')
	{
		if (prev  == ';' || prev == '|')
			return (index);

		if (prev == '&')
		{
			count = countRepeat(input, 0);
			if (count == 0 || count > 1)
				return (index);
		}
	}

	return (sepErrorCheck(input + 1, index + 1, *input));
}





int findFirst(char *input, int *b)
{
	for (*b = 0; input[*b]; *b += 1)
	{
		if (input[*b] == ' ' || input[*b] == '\t')
			continue;
		if (input[*b] == ';' || input[*b] == '|' || input[*b] == '&')
			return (-1);
		break;
	}

	return (0);
}
