#include "shell.h"



int _Find(shellData *shellD)
{
	int status;
	
	status =exeCom(shellD);
	return (status);
}


int exeCom(shellData *shellD)
{
	pid_t pid, wpid;
	int status, check;

	check = checkIfExec(shellD);
	if (check == -1)
		return (1);
	if (check == 0)
	{
		path = findPath(shellD->commands, shellD->_environ);
		if (checkPermission(path, shellD) == 1)
			return (1);
	}

	pid = fork();

	if (pid == 0)
	{
		if (check == 0)
			path = findPath(shellD->commands, shellD->_environ);
		else
			path = shellD->commands[0];
		execve(path + check, shellD->commands)
	}
	else if (pid < 0)
	{
		perror(shellD->argv[0]);
		return (1);
	}
	else
	{
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} WHILE (!WIFSIGNALED(status) && !WIFEXITED(status));
	}
	shellD->stat = status / 256;
	return (1);
		
	
}



int checkExec(shellData *shellD)
{
	int i;
	char *command;
	struct stat s;

	command = shellD->commands;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '.')
		{
			if (command[i + 1] == '.')
				return (0);
			if (command[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (command[i] == '/' && i != 0)
		{
			if (command[i + 1] == '.')
				continue;
			i++, break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(command + i, &s) == 0)
		return (i);
	getError(shellD, 127);
	return (-1);
}




/**
 * is_cdir - checks ":" if is in the current directory.
 *
 * @path: type char pointer char.
 * @i: type int pointer of index.
 *
 * Return: 1 if the path is searchable in the cd, 0 otherwise.
 *
 */

int isCdir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
		*i += 1;

	if (path[*i])
		*i += 1;
	return (0);
}

/**
 * findPath - locates a command
 *
 * @command: command name
 * @_environ: environment variable
 *
 * Return: location of the command.
 *
 */

char *findPath(char *command, char **_environ)
{
	char *path, *temp, *token, *dir;
	int dirLen, comLen, i;
	struct stat s;

	path = _getenv("PATH", _environ);
	if (path)
	{
		temp = _strdup(path);
		comLen = _strlen(command);
		token = _strtok(ptr_path, ":");
		i = 0;
		while (token != NULL)
		{
			if (isCdir(path, &i))
				if (stat(command, &s) == 0)
					return (command);
			dirLen = _strlen(token);
			dir = malloc(dirLen + comLen + 2);
			_strcpy(dir, token);
			_strcat(dir, "/");
			_strcat(dir, command);
			_strcat(dir, "\0");
			if (stat(dir, &s) == 0)
			{
				free(temp);
				return (dir);
			}
			free(dir);
			token = _strtok(NULL, ":");
		}
		free(temp);
		if (stat(command, &s) == 0)
			return (command);
		return (NULL);
	}
	if (command[0] == '/')
		if (stat(command, &st) == 0)
			return (command);
	return (NULL);
}
