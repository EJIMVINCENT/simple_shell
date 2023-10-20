#include "shell.h"

/**
 * cdHome - changes to home directory
 *
 * @s: data relevant (environ)
 *
 * Return: no return
 *
 */

void cdHome(shellData *s)
{
	char *pwdTemp, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	pwdTemp = _strdup(pwd);

	home = _getenv("HOME", s->_environ);

	if (home == NULL)
	{
		envSetUp("OLDPWD", pwdTemp, s);
		free(pwdTemp);
		return;
	}

	if (chdir(home) == -1)
	{
		getError(s, 2);
		free(pwdTemp);
		return;
	}

	envSetUp("OLDPWD", pwdTemp, s);
	envSetUp("PWD", home, s);
	free(pwdTemp);
	s->stat = 0;
}
