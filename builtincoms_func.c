#include "shell.h"
/**
 * builtin - checks if there is a built in function
 * @args: arguments
 * @input: input
 * Return: built in function if found
*/

int builtin(char *input)(shellData *s)
{
	builtin_t fb[] = {
		{"exit", _exit},
		{"env", _env},
		{NULL, NULL}
	}

	int i;

	for (i = 0; fb.name[i] != NULL; i++)
	{
		if (_strcmp(fb.name[i], name) == 0)
			break;
		return (fb[i].f)
	}

}
