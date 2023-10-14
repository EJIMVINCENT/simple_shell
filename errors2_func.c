#include "shell.h"



/**
 * cdStrcat - function that concatenates the message for cd error
 *
 * @s: pointer to shellData struct
 * @msg: message to print
 * @error: output message
 * @ver_str: counter lines
 *
 * Return: error message
 */

char *cdStrcat(shellData *s, char *msg, char *error, char *ver_str)
{
	char *flag;

	_strcpy(error, s->argv[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, s->commands[0]);
	_strcat(error, msg);
	if (s->args[1][0] == '-')
	{
		flag = malloc(3);
		flag[0] = '-';
		flag[1] = s->commands[1][1];
		flag[2] = '\0';
		_strcat(error, flag);
		free(flag);
	}
	else
	{
		_strcat(error, s->commands[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * errorCd - error message for cd command in get_cd
 *
 * @s: pointer to shellData struct
 *
 * Return: Error message
 *
 */

char *errorCd(shellData *s)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = _itoa(s->count);
	if (s->commands[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(s->args[1]);
	}

	length = _strlen(s->argv[0]) + _strlen(s->commands[0]);
	length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = cdStrcat(s, msg, error, ver_str);

	free(ver_str);

	return (error);
}
