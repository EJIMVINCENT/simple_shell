#include "shell.h"

/**
 * parseCommands - parses userinput
 *
 * @input: pointer to user input
 * @shellD: pointer to shellData struct
 *
 * Return: returns 1 on success and 0 otherwise
 *
 */

int parseCommands(char *input, shellData *shellD)
{
	int status = 1;
	sep *sepHead, *sepTemp;
	commands *comHead, *comTemp;

	sepHead = NULL;
	comHead = NULL;

	addComSep(&sepHead, &comHead, input);
	sepTemp = sepHead;
	comTemp = comHead;

	while (comTemp != NULL)
	{
		shellD->input = comTemp->command;
		shellD->commands = splitCommand(shellD->input);
		status = _Find(shellD);
		free(shellD->commands);
		if (status == 0)
			break;
		findNext(sepTemp, comTemp, shellD);
		if (comTemp)
			comTemp = comTemp->next;
	}
	freeComNode(&comHead);
	freeSepNode(&sepHead);
	if (status == 0)
		return (0);
	return (1);
}

/**
 * addComSep - adds calls function to add command to commands
 * struct and seperators to sep struct
 *
 * @sepHead: pointer to sepHead pointer
 * @comHead: pointer to comHead pointer
 * @input: pointer to char
 */

void addComSep(sep **sepHead, commands **comHead, char *input)
{
	int i;
	char *temp;

	input = charSwap(input, 0);

	for (i = 0; input[i] != 0; i++)
	{
		if (input[i] == ';')
			addSepNode(sepHead, input[i]);
		if (input[i] == '|' || input[i] == '&')
			addSepNode(sepHead, input[i]), i++;
	}

	temp = _strtok(input, ";&|");
	do {
		temp = charSwap(temp, 1);
		addComNode(comHead, temp);
		temp = _strtok(NULL, ";|&");
	} while (temp != NULL);
}

/**
 * splitCommand - splits commands and arguments
 *
 * @input: input string (commands)
 *
 * Return: returns a pointer to an array of strings with
 * command at index 0 and followed by args to command
 * otherwise NULL
 *
 */

char **splitCommand(char *input)
{
	char *token;
	char **commands;
	size_t size, i;

	size = TOKBUFF;
	commands = malloc(sizeof(char *) * (size));
	if (commands == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(input, DELIM);
	commands[0] = token;

	for (i = 1; token; i++)
	{
		if (i == size)
		{
			size += TOKBUFF;
			commands = customRealloc(commands, i, sizeof(char *) * size);
			if (commands == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}

		token = _strtok(NULL, DELIM);
		commands[i] = token;
	}
	return (commands);
}

/**
 * charSwap - swaps command seperators for non
 * printable char
 *
 * @input: input string (command)
 * @status: shell status
 *
 * Return: returns input
 *
 */

char *charSwap(char *input, int status)
{
	int i = 0;

	if (status == 0)
	{
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '|')
			{
				if (input[1 + i] != '|')
					input[i] =  16;
				else
					i++;
			}
			if (input[i] == '&')
			{
				if (input[i + 1] != '&')
					input[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; input[i]; i++)
		{
			input[i] = (input[i] == 16 ? '|' : input[i]);
			input[i] = (input[i] == 12 ? '&' : input[i]);
		}
	}
	return (input);
}

/**
 * findNext - finds next command to execute
 *
 * @sepH: pointer to sep struct containing seperators
 * @comH: pointer to commands struct containing commands
 * @shellD: pointer to shellData
 */

void findNext(sep *sepH, commands *comH, shellData *shellD)
{
	int status;
	sep *s;
	commands *c;

	status = 1;
	s = sepH;
	c = comH;

	while (s != NULL && status != 0)
	{
		if (shellD->stat == 0)
		{
			if (s->separator == '&' || s->separator == ';')
				status = 0;
			if (s->separator == '|')
				c  = c->next, s = s->next;
		}
		else
		{
			if (s->separator == '|' || s->separator == ';')
				status = 0;
			if (s->separator == '&')
				c = c->next, s = s->next;
		}
		if (s != NULL && !status)
			s = s->next;
	}
	sepH = s;
	comH = c;
}
