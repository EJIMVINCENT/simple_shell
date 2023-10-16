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
