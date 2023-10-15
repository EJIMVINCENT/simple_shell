#include "shell.h"

/**
 * EnvCmp - checks if first characters in name are
 * same with 1st char in envname
 *
 * description: _getenv helper function
 *
 * @envName: name of the env
 * @name: name of path to check
 *
 * Return: lenght of the path name if found
 * otherwise 0;
 *
 */

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

/**
 * _getenv - custom getenv (get the values of an enviromental
 * variable)
 *
 * @name: Name of env to be searched
 * @_environ: pointer to environmental variables list
 *
 * Return: return the enviromental variable if found
 * otherwise NULL
 *
 */

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

/**
 * _env - custom env command
 *
 * description: prints the values of the env to stdout
 *
 * @shellD: pointer to shellData structure
 *
 * Return: Always returns 1
 *
 */

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
