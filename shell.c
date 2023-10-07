#include "shell.h"







int main(int ac, char *argv[])
{
	(void) ac;
	(void) argv;
	char *input;
	size_t count = 0;
	char **commands;

	while (1)
	{

		input = getPrompt(&count);
		commands = perseCom(input);
		exeCom(commands);
	}

}
