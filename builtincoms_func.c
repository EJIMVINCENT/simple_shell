#include "shell.h"

/**
 * findBuiltIn - checks if command is a built in function
 *
 * @input: user input to be checked
 * @s: pointer to shellData struct
 *
 * Return: built in function if found
 *
 */

int (*findBuiltIn(char *input))(shellData *s)
{
	customeB fb[] = {
		{"exit", exitShell},
		{"env", _env},
		{NULL, NULL}
	};

	int i;

	for (i = 0; fb[i].name != NULL; i++)
	{
		if (_strcmp(fb[i].name, input) == 0)
			break;
	}
	return (fb[i].f);
}

/**
 * exitShell - exits the shell
 *
 * @shellD: pointer to shellData structure
 *
 * Return: return 0 on success otherwise 1
 *
 */

int exitShell(shellData *shellD)
{
	unsigned int exitStat;
	int checkDigit, len, valid;

	if (shellD->commands[1] != NULL)
	{
		exitStat = _atoi(shellD->commands[1]);
		checkDigit = _isdigit(shellD->commands[1]);
		len = _strlen(shellD->commands[1]);
		valid = exitStat > (unsigned int)INT_MAX;
		if (!checkDigit || len > 10 || valid)
		{
			getError(shellD, 2);
			shellD->stat = 2;
			return (1);
		}
		shellD->stat = (exitStat % 256);
	}
	return (0);
}



int _setEnv(shellData s)
{
	if (s->commands[1] == NULL || s->commands[2] == NULL)
	{
		getError(s, -1);
		return (1);
	}

	envSetUp(s->[1], s->[2], s);
}




void envSetUp(char *name, char *value, shellData *s)
{
	int i = 0;
	char *tempEnv, *envName;

	for (; s->_environ[i]; i++)
	{
		tempEnv = _strdup(s->_environ[i]);
		envName = _strtok(tempEnv, "=");
		if (_strcmp(tempEnv, name) == 0)
		{
			free(s->_environ[i]);
			s->_environ[i] = setInfo(envName, value);
			free(tempEnv);
			return;
		}
		free(tempEnv);
	}

	s->_environ = customRealloc(s->_environ, i, sizeof(char *) * (i + 2));
	s->_environ[i] = setInfo(name, value);
	s->_environ[i + 1] = NULL;
}








int _unsetEnv(shellData *s)
{
	char **newEnviron;
	char *tempEnv, *envName;
	int i, j, k = -2;

	if (s->commands[1] == NULL)
	{
		getError(datash, -1);
		return (1);
	}
	for (i = 0; s->_environ[i]; i++)
	{
		tempEnv = _strdup(datash->_environ[i]);
		envName = _strtok(tempEnv, "=");
		if (_strcmp(envname, s->commands[1]) == 0)
			k = i;
		free(tempEnv);
	}
	if (k == -2)
	{
		getError(datash, -1);
		return (1);
	}
	newEnviron = malloc(sizeof(char *) * (i));
	for (i = 0, j = 0; s->_environ[i]; i++)
	{
		if (i != k)
			newEnviron[j++] = s->_environ[i];

	}
	newEnviron[j] = NULL;
	free(s->_environ[k]);
	free(s->_environ);
	s->_environ = newEnviron;
	return (1);
}
