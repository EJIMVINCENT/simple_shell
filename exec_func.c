#include "shell.h"


void exeCom(char **commands)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
 		write(STDERR_FILENO, "Error forking process.\n", sizeof(    "Error forking process.\n"));
		exit(EXIT_FAILURE);
 	}
	else if (child_pid == 0)
	{
		execvp(commands[0], commands);
	}
 
}
