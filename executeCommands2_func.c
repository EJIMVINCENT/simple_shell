#include "shell.h"


/**
 * checkPermission - verifies if user has permissions to access
 *
 * @path: destination directory
 * @s: data structure
 *
 * Return: 1 if there is an error, 0 if not
 *
 */

int checkPermission(char *path,shellData *s)
{
	if (path == NULL)
		getError(s, 127), return (1);
	
	if (_strcmp(s->commands[0], path) != 0)
	{
		if (access(path, X_OK) == -1)
		{
			getError(s, 126);
			free(path);
			return (1);
		}
		free(path);
	}
	else
	{
		if (access(s->commands[0], X_OK) == -1)
		{
			getError(s, 126);
			return (1);
		}
	}

	return (0);
}
