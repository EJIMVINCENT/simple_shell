#include "shell.h"

/**
 * main - Entry point
 *
 * @ac: Argument count
 * @argv: String of array
 *
 * Return: 0
 */

int main(int ac, char *argv[])
{
	shellData shellD;

	(void)ac;

	/* code main loop */
	shellLoop(&shellD, argv);
	if (shellD.stat < 0)
		return (255);
	return (shellD.stat);
}


/**
 * setData - sets data
 *
 * @shellD: A pointer
 * @argv: An array of strings
 *
 * Return: void
 */

void setData(shellData *shellD, char **argv)
{
	unsigned int i;

	signal(SIGINT, Csignal);
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


/**
 * Csignal - Handle the crtl + c call in prompt
 *
 * @s: Signal handler
 *
 */

void Csignal(int s)
{
	(void)s;
	write(STDOUT_FILENO, "\n($) ", 5);
}
