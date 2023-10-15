#include "shell.h"

/**
 * freeEnviron - free _environs list
 *
 * @s: pointer to shellData struct
 *
 */

void freeEnviron(shellData *s)
{
	unsigned int i;

	for (i = 0; s->_environ[i]; i++)
	{
		free(s->_environ[i]);
	}

	free(s->_environ);
	free(s->pid);
}
