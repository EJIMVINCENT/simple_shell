#include "shell.h"

/**
 * shellLoop - code main loop, reaptedly calls all functions
 *
 * @shellD: pointer to shellData struct
 * @argv: pointer to command line input
 *
 */

void shellLoop(shellData *shellD, char *argv[])
{
	int status, check, i;
	char *input;

	status = 1;
	/* initialize shellD variables */
	setData(shellD, argv);
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
				shellD->stat = 2, free(input);
				continue;
			}

			input = varExpansion(input, shellD);
			status = parseCommands(input, shellD);
			shellD->count += 1;
			free(input);
		}
		else
			status = 0, free(input);
	}
	freeEnviron(shellD);
}
