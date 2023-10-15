#include "shell.h"

/**
 * main - Entry point
 * @ac: Argument count
 * @argv: String of array
 *
 * Return: 0
 */
int main(int ac, char *argv[])
{
	shellData shellD;

	(void)ac;

	/* initialize shellD variables */
	setData(&shellD, argv);
	/* code main loop */
	shellLoop(&shellD);
	return (0);
}


/**
 * setData - sets data
 * @shellD: A pointer
 * @argv: An array of strings
 *
 * Return: void
 */
void setData(shellData *shellD, char **argv)
{
	unsigned int i;

	shellD->argv = argv;
	shellD->stat = 0;
	shellD->count = 1;
	shellD->commands = NULL;

	for (i = 0; environ[i]; i++)
		;
	i++;

	shellD->_environ = malloc(sizeof(char *) * i);

	for (i = 0; environ[i]; i++)
		shellD->_environ[i] = _strdup(environ[i]);

	shellD->_environ[i] = NULL;
	shellD->pid = _itoa(getpid());
}
