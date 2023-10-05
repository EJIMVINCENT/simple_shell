#include "shell.h"





void printPrompt()
{
	putString("($) ");
}


void getPrompt(char *input, int *count)
{
	ssize_t = i;

	do
	{
		i = getline(&input, count, STDIN_FILENO);
		input[*count - 1] = '\0';

		if (i = -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}

	}while (input[0] == '\0')

}
