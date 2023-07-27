#include "main.h"

/**
 * exec_bltn - checking for built in and exect
 * @d: data struct to input
 * Return: 1 if built in, 0 if not
 */
int exec_bltn(data *d)
{
	bltn bltn[] = {
		{"exit", bltn_exit},
		{"env", bltn_env},
		{"setenv", bltn_setenv},
		{"unsetenv", bltn_unsetenv},
		{"cd", bltn_cd},
		{NULL, NULL},
	};
	int i = 0;

	for (i = 0; bltn[i].cmd; i++)
	{
		if (_strcmp(d->av[0], bltn[i].cmd) == 0)
		{
			bltn[i].f(d);
			return (1);
		}
	}
	return (0);
}

/**
 * bltn_exit - shell exiting
 * @d: data struct input
 * Return: void
 */
void bltn_exit(data *d)
{
	const char *errorStrng = "./hsh: 1: exit: false numb: ";

	if (d->av[1])
	{
		if (d->av[1][0] != '-' && _isnumber(d->av[1]))
			d->last_status = atoi(d->av[1]);
		else
		{
			write(STDERR_FILENO, errorStrng, strlen(errorStrng));
			write(STDERR_FILENO, d->av[1], strlen(d->av[1]));
			write(STDERR_FILENO, "\n", 1);
			d->last_status = 2;
		}
	}
	free_array(d->av);
	free(d->cmd);
	if (d->flg_setenv)
		free_array(environ);
	exit(d->last_status);
}

/**
 * bltn_env - printing current envirt
 * @d: data struct input
 * Return: void
 */
void bltn_env(data *d)
{
	int i = 0;

	(void)d;
	while (environ[i])
	{
		_printf(environ[i]);
		_printf("\n");
		i++;
	}
}
/**
 * bltn_setenv - create new envi variable,
 * @d: data struct input
 * Return: void
 */

void bltn_setenv(data *d)
{
	(void)d;
	if (d->av[1] && d->av[2])
	{
		if (_setenv(d, d->av[1], d->av[2]) == -1)
		{
			perror("setenv");
		}
	}
}

/**
 * bltn_unsetenv - Removing envir variable
 * @d: data struct input
 * Return: void
 */
void bltn_unsetenv(data *d)
{
	int i, j;
	int len;

	(void)d;
	if (!d->av[1] || !getenv(d->av[1]))
	{
		_perror(d->shell_cr, "variable not found.");
		return;
	}
	len = strlen(d->av[1]);
	for (i = 0; environ[i]; i++)
		if (strncmp(environ[i], d->av[1], len) == 0 && environ[i][len] == '=')
			for (j = i; environ[j]; j++)
				environ[j] = environ[j + 1];
}
