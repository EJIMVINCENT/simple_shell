#include "shell.h"






int EnvCmp(const char *envName, const char *name)
{
	int i;

	for (i = 0; envName[i] != '='; i++)
	{
		if (envName[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}



char *_getenv(const char *name, char **_environ)
{
	char *ptr;
	int i, check;

	ptr = NULL;
	check = 0;
	for (i = 0; _environ[i]; i++)
	{
		check = EnvCmp(_environ[i], name);
		if (check)
		{
			ptr = _environ[i];
			ptr += check;
			break;
		}
	}

	return (ptr);
}


int _env(shellData *shellD)
{
	int i, j;

	for (i = 0; shellD->_environ[i]; i++)
	{

		for (j = 0; shellD->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, shellD->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	shellD->stat = 0;

	return (1);
}