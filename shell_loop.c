#include "shell.h"



void shellLoop(shellData *shellD)
{
	int status, check, i;
	char *input;

	status = 1;

	while (status == 1)
	{
		write(STDIN_FILENO, "($) ", 4);
		input = readLine(&check);

		if (check != -1)
		{
						
			input = remComment(input);
			if (input == NULL)
				continue;
			
			i = syntaxErrorCheck(input, shellD);
			if (i == 1)
			{
				shellD->stat = 2;
				free(input);
				continue;
			}

			input = rep_var 

			
		}
	}
}
