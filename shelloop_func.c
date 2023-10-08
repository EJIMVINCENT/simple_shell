#include "shell.h"



void shellLoop(shellData *sd)
{
	char *buffer = NULL;
	size_t len;
	int i;
	pid_t child;

	while (1)
	{
		if (isatty(0) == 1)
			write(STDOUT_FILENO, "($) ", 4);

		i = getline(&buffer, &len, stdin);
		if (i == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		
		sd->input = buffer;
		if (_strcmp(buffer, "exit\n") == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (_strcmp(buffer, "\n") == 0 || checkSpace(buffer) == 0)
			continue;

		parseArgs(sd);
		check = findPath(sd);
		

		if (check == 0)
		{
			child = fork();
			if (child == -1)
				free(buffer), perror("fork");

			if (child )
	}

}
