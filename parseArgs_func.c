#include "shell.h"






void parseArgs(shellData *sd)
{
	char *temp, *input = _strdup(sd->input); 
	char **commands;
	char *token = " \t\n";
	int count = 0, i = 0;

	temp = input;
	input = _strtok(input, " \n\t");
	while (input != NULL)
	{
		count++;
		input = _strtok(NULL, " \n\t");
	}


	commands = malloc(sizeof(char *) * (count + 1));
	if (commands == NULL)
		sd->commands = NULL, return;
	

	input = temp;
	input = _strtok(input, token);
	while (commands != NULL)
	{
		commands[i++] = (input);
		input = _strtok(NULL, token);	
	}
	commands[i] = NULL;

	sd->commands = commands;
}



int findPath(shellData *sd)
{
	char **commands = sd->commands;
	char *arg = command[0];
	int count = 0, status;

	status = _getenv(sd);
	if (status = 0)
		return (status);
	return (1);
}
