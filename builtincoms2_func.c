#include "shell.h"


/**
 * setInfo - copies info to set
 * a new env
 *
 * @name: name
 * @value: value
 *
 * Return: new variable
 */

char *setInfo(char *name, char *value)
{
	char *new;
	int nlen, vlen, len;

	nlen = _strlen(name);
	vlen = _strlen(value);
	len = nlen + vlen + 2;
	new = malloc(sizeof(char) * (len));
	if (new == NULL)
		return (NULL);
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}
