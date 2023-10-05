#include "shell.h"






char **perseCom(char *input)
{
	char *args[128];
	char *token;
	int count = 0;

        token = strtok((char *)command, " ");
        while (token != NULL)
	{
		args[count] = _strdup(token);
		if (args[count] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		count++;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	return (args);
}
