#include "shell.h"


int putString(char *string)
{
	int count;
	count = write(STDOUT_FILENO, string, _strlen(string));
	
	if (count == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	return (count);
}
