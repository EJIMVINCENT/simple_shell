#include "shell.h"






char **perseCom(char *input)
{
	char **args;
	char *token;
	int count = 0;

	args = malloc(100 * sizeof(char *));

        token = strtok(input, " ");
        while (token != NULL)
	{
		args[count] = _strdup(token);	
		count++;
		token = strtok(NULL, " ");
	}
	args[count] = NULL;

	return (args);
}
