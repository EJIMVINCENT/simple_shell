#include "shell.h"



void shellLoop(shellData *sd)
{
	char *buffer;
	size_t len;
	int i;
	pid_t child;

	while (1)
	{
		buffer = NULL;
		if (isatty(0) == 1)
			write(STDOUT_FILENO, "($) ", 4);

		i = getline(&buffer, &len, stdin);
		if (i == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}

		if (buffer == NULL)
			continue;
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
		if (check == 1)
		{
			child = fork();
			if (child == -1)
			{
				free(buffer), perror("fork");
				continue;
			}

			else if (child == 0)
			{
				i = execute(shellData);
				continue;
			}
		}
	}

}
