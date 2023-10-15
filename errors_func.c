#include "shell.h"

/**
 * errorEnv - error message for env add/rem
 * operation failure
 * 
 * @shellD: pointer to shellData struct
 *
 * Return: return error message, otherwise NULL
 *
 */

char *errorEnv(shellData *shellD)
{
	int len;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = _itoa(shellD->count);
	msg = ": Unable to add/remove from environment\n";
	len = _strlen(shellD->argv[0]) + _strlen(ver_str);
	len += _strlen(shellD->commands[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (len + 1));
	if (error == NULL)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, shellD->argv[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, shellD->commands[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}

/**
 * errorPath126 - prints error message for file perm
 *
 * @shellD: pointer to shellData struct
 *
 *  Return: return error message, otherwise NULL
 *
 */

char *errorPath126(shellData *shellD)
{
	int len;
	char *ver_str;
	char *error;

	ver_str = _itoa(shellD->count);
	len = _strlen(shellD->argv[0]) + _strlen(ver_str);
	len += _strlen(shellD->commands[0]) + 24;
	error = malloc(sizeof(char) * (len + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, shellD->argv[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, shellD->commands[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * getError - gets and writes error to stdout
 *
 * @shellD: pointer to shellData struct
 * value: error value
 *
 * Return: value(error value)
 *
 */

int getError(shellData *shellD, int value)
{
	char *error;

	switch (value)
	{
	case -1:
		error = errorEnv(shellD);
		break;
	case 126:
		error = errorPath126(shellD);
		break;
	case 127:
		error = errorNotFound(shellD);
		break;
	case 2:
		if (_strcmp("exit", shellD->commands[0]) == 0)
			error = errorExit(shellD);
		else if (_strcmp("cd", shellD->commands[0]) == 0)
			error = errorCd(shellD);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	shellD->stat = value;
	return (value);
}

/**
 * errorNotFound - error message for command not found
 *
 * @s: pointer to shellData struct
 *
 * Return: Error message
 *
 */

char *errorNotFound(shellData *s)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = _itoa(s->count);
	length = _strlen(s->argv[0]) + _strlen(ver_str);
	length += _strlen(s->commands[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, s->argv[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, s->commands[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * errorExit -  error message for exit
 *
 * @s: pointer to shellData struct
 *
 * Return: Error message
 *
 */

char *errorExit(shellData *s)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = _itoa(s->count);
	length = _strlen(s->argv[0]) + _strlen(ver_str);
	length += _strlen(s->commands[0]) + _strlen(s->commands[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, s->argv[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, s->commands[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, s->commands[1]);
	_strcat(error, "\n\0");
	free(ver_str);

	return (error);
}
