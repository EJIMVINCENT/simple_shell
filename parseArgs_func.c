#include "shell.h"






void parseArgs(shellData *sd)
{
	char *input = _strdup(sd->input); 
	char **commands;
	char *token = " \t\n";
	int count = 0, i = 0;

	input = _strtok(input, " \n\t");
	while (input != NULL)
	{
		count++;
		input = _strtok(NULL, " \n\t");
	}
	free(input);

	commands = malloc(sizeof(char *) * (count + 1));
	if (commands == NULL)
		sd->commands = NULL, return;
	

	input = _strdup(sd->input)
	input = _strtok(input, token);
	while (commands != NULL)
	{
		commands[i++] = input;
		input = _strtok(NULL, token);	
	}
	commands[i] = NULL;

	sd->commands = commands;
}



int findPath(shellData sd)
{
	char **commands = sd->commands;
	char *arg = command[0];
	int count = 0;

	
	

}
