#include "shell.h"

/**
 * setInfo - copies info to set
 * a new env
 *
 * @name: name
 * @value: value
 *
 * Return: new variable
 */

char *setInfo(char *name, char *value)
{
	char *new;
	int nlen, vlen, len;

	nlen = _strlen(name);
	vlen = _strlen(value);
	len = nlen + vlen + 2;
	new = malloc(sizeof(char) * (len));
	if (new == NULL)
		return (NULL);
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * _cd - changes current directory
 *
 * @s: pointer to shellData struct
 *
 * Return: always returns 1
 *
 */

int _cd(shellData *s)
{
	char *arg;
	int Home, Dhome, Uhome;

	arg = s->commands[1];

	if (arg != NULL)
	{
		Home = _strcmp("$HOME", arg);
		Dhome = _strcmp("~", arg);
		Uhome = _strcmp("--", arg);
	}

	if (arg == NULL || !Home || !Dhome || !Uhome)
	{
		cdHome(s);
		return (1);
	}

	if (_strcmp("-", arg) == 0)
	{
		cdPrevious(s);
		return (1);
	}

	if (_strcmp(".", arg) == 0 || _strcmp("..", arg) == 0)
	{
		cdParent(s);
		return (1);
	}

	cdTo(s);

	return (1);
}

/**
 * cdTo - changes to a directory given
 * by the user
 *
 * @s: data relevant (directories)
 *
 * Return: no return
 *
 */

void cdTo(shellData *s)
{
	char pwd[PATH_MAX];
	char *path, *pwdCp, *pathCp;

	getcwd(pwd, sizeof(pwd));

	path = s->commands[1];
	if (chdir(path) == -1)
	{
		getError(s, 2);
		return;
	}

	s->stat = 0;
	pwdCp = _strdup(pwd);
	pathCp = _strdup(path);
	envSetUp("OLDPWD", pwdCp, s);
	envSetUp("PWD", pathCp, s);

	free(pathCp);
	free(pwdCp);
	chdir(path);
}

/**
 * cdParent - changes to the parent pathectory
 *
 * @s: pointer to shellData struct
 *
 * Return: no return
 *
 */

void cdParent(shellData *s)
{
	char pwd[PATH_MAX];
	char *path, *pwdCp, *pwdtemp;

	getcwd(pwd, sizeof(pwd));
	pwdCp = _strdup(pwd);
	envSetUp("OLDPWD", pwdCp, s);
	path = s->commands[1];
	if (_strcmp(".", path) == 0)
	{
	envSetUp("PWD", pwdCp, s);
		free(pwdCp);
		return;
	}
	if (_strcmp("/", pwdCp) == 0)
	{
		free(pwdCp);
		return;
	}
	pwdtemp = pwdCp;
	strRev(pwdtemp);
	pwdtemp = _strtok(pwdtemp, "/");
	if (pwdtemp != NULL)
	{
		pwdtemp = _strtok(NULL, "\0");

		if (pwdtemp != NULL)
			strRev(pwdtemp);
	}
	if (pwdtemp != NULL)
		chdir(pwdtemp), envSetUp("PWD", pwdtemp, s);
	else
		chdir("/"), envSetUp("PWD", "/", s);

	s->stat = 0;
	free(pwdCp);
}

/**
 * cdPrevious - changes to the previous directory
 *
 * @s: pointer to shellData struct
 *
 * Return: no return
 *
 */

void cdPrevious(shellData *s)
{
	char pwd[PATH_MAX];
	char *prePwd, *oldpwd, *tempPwd, *tempOldPwd;

	getcwd(pwd, sizeof(pwd));
	tempPwd = _strdup(pwd);

	oldpwd = _getenv("OLDPWD", s->_environ);

	if (oldpwd == NULL)
		tempOldPwd = tempPwd;
	else
		tempOldPwd = _strdup(oldpwd);

	envSetUp("OLDPWD", tempPwd, s);

	if (chdir(tempOldPwd) == -1)
		envSetUp("PWD", tempPwd, s);
	else
		envSetUp("PWD", tempOldPwd, s);

	prePwd = _getenv("PWD", s->_environ);

	write(STDOUT_FILENO, prePwd, _strlen(prePwd));
	write(STDOUT_FILENO, "\n", 1);

	free(tempPwd);
	if (oldpwd)
		free(tempOldPwd);
	chdir(prePwd);
	s->stat = 0;
}
