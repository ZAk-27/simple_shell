#include "main.h"

/**
 * _printf - printing a string t
 * @strl: string input
 * Return: void
 */
void _printf(const char *strl)
{
	if (!strl)
		return;
	while (*strl)
	{
		write(STDOUT_FILENO, strl, 1);
		strl++;
	}
}

/**
 * free_array - free an array of pointrs
 * @array: array of pointers
 * Return: void
 */
void free_array(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}

	free(array);
}

/**
 * split - split string
 * @d: data struct input
 * @delim: string input
 * Return: void
 */
void split(data *d, const char *delim)
{
	char *tkn;
	int ntkn = 0;

	d->av = malloc(2 * sizeof(char *));
	if (d->av == NULL)
	{
		free(d->cmd);
		perror(d->shell_cr);
		exit(EXIT_FAILURE);
	}
	d->av[0] = NULL;
	d->av[1] = NULL;

	tkn = strtok(d->cmd, delim);
	while (tkn)
	{
		d->av = realloc(d->av, (ntkn + 2) * sizeof(char *));
		if (d->av == NULL)
			goto free;
		d->av[ntkn] = _strdup(tkn);
		if (d->av[ntkn] == NULL)
			goto free;
		ntkn++;
		tkn = strtok(NULL, delim);
	}
	d->av[ntkn] = NULL;
	return;
free:
	free_array(d->av);
	free(d->cmd);
	perror(d->shell_cr);
	exit(EXIT_FAILURE);
}

/**
 * init_data - init data
 * @d: data struct input
 * @shell_cr: sh string input
 * Return: void
 */

void init_data(data *d, const char *shell_cr)
{
	d->cmd = NULL;
	d->av = NULL;
	d->shell_cr = shell_cr;
	d->last_status = EXIT_SUCCESS;
	d->flg_setenv = 0;
}

/**
 * read_cmd - geting commnd from  prompt and data struct
 * @d: data struct input
 * Return: void
 */
void read_cmd(data *d)
{
	size_t n = 0;
	ssize_t nreead;
	int i = 0;

	nreead = _getline(&d->cmd, &n, stdin);

	if (nreead == -1)
	{
		free(d->cmd);
		exit(EXIT_SUCCESS);
	}

	d->cmd[nreead - 1] = '\0';
	_trim(d->cmd);
	/* replacing hashtag with EOL */
	for (i = 0; d->cmd[i] != '\0'; i++)
	{
		if (d->cmd[0] == '#' || (d->cmd[i] == '#' && d->cmd[i - 1] == ' '))
		{
			d->cmd[i] = '\0';
			break;
		}
	}
	_trim(d->cmd);
}
