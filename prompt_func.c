#include "shell.h"





void printPrompt()
{
	putString("($) ");
}


char *getPrompt(size_t *count)
{
	size_t bufsize = 0;
	char *input = NULL;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		*count = getline(&input, &bufsize, stdin);
		input[*count - 1] = '\0';

		if (*count == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}

		if (input[0] != '\0');
			return (input);
	}

}
