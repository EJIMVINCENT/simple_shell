#include "shell.h"



int parseCommands(char *input, shellDaata shellD)
{
	int status = 1;
	sep *sepHead, *sepTemp;
	commands *comHead, comTemp;

	sepHead = NULL;
	comHead = NULL;

	addComSep(&sepHead, &comHead, input);

	while (status)
	{
		
	}
}


void addComSep(sep *sepHead, commands *comHead, char *input)
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


char *charSwap(char *input, int status)
{
	int i = 0;

	if (status == 0)
	{
		for(i = 0; input[i]; i++)
		{
			if(input[i] == '|')
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
