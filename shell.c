#include "shell.h"







int main(int ac, char *argv[])
{
	char input[80];
	int count;
	char **commands;

	while (1)
	{
		printPrompt();
		getPrompt(input, &count);
		commands =perseCom(input);
		executeCom(commands);
	}

}
