#include "shell.h"






int main (int ac, char *argv[])
{
	shellData shellD;

	/* initialize shellD variables */
	setData(&shellD, argv);
	/* code main loop */
	shellLoop(&shellD);

	freeEnviron(&shellD);
	if (shellD.stat < 0)
		return (255);
	return (shellD.stat);
}

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
