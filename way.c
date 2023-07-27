#include "main.h"

/**
 * _getenv - env variable retriving.
 * @name: string input
 * Return: value of an envir variable
 */

char *_getenv(char *name)
{
	int i = -1;
	size_t name_len;

	if (name == NULL || *name == '\0')
		return (NULL);
	if (environ == NULL)
		return (NULL);

	name_len = _strlen(name);

	while (environ[++i])
	{
		if (!_strncmp(environ[i], name, name_len) && environ[i][name_len] == '=')
		{
			return (environ[i] + name_len + 1);
		}
	}
	return (NULL);
}

/**
 * _which - locate the exact file.
 * @d: string input
 * Return: void
 */
int _which(data *d)
{
	char *tkn, *way,
		*ways = malloc(_strlen(_getenv("PATH") ? _getenv("PATH") : "") + 1);
	size_t tkn_len;
	int find = -1;

	if (!_getenv("PATH"))
		goto step_out;
	_strcpy(ways, _getenv("PATH"));
	if (ways == NULL)
		goto step_out;
	tkn = strtok(ways, ":");
	while (tkn)
	{
		tkn_len = _strlen(tkn) + _strlen(d->av[0]) + 2;
		way = malloc(tkn_len);
		if (way == NULL)
			return (find);
		_strcpy(way, tkn);
		_strcat(way, "/");
		_strcat(way, d->av[0]);
		if (access(way, F_OK) == 0)
		{
			free(d->av[0]);
			d->av[0] = _strdup(way);
			free(way);
			find = 0;
			break;
		}
		free(way);
		tkn = strtok(NULL, ":");
	}
step_out:
	free(ways);
	return (find);
}

/**
 * cr_nv_entry - Initializing a new envir variable,
 * @name: variable name
 * @value: variable value
 * Return: void
 */
char *cr_nv_entry(char *name, char *value)
{
	size_t nv_len = strlen(name) + strlen(value) + 2;
	char *nv_entry = malloc(nv_len);

	if (nv_entry == NULL)
		return (NULL);

	strcpy(nv_entry, name);
	strcat(nv_entry, "=");
	strcat(nv_entry, value);

	return (nv_entry);
}
/**
 * _nv_environ - Initializing a nv envir variable,
 *  or modifying existing
 * @name: variable name
 * @value: variable value
 * Return: void
 */
char **_nv_environ(char *name, char *value)
{
	int env_len = 0, i = 0;
	char *nv_entry;
	char **nv_environ;

	while (environ[env_len])
		env_len++;
	nv_entry = cr_nv_entry(name, value);
	if (nv_entry == NULL)
		return (NULL);
	nv_environ = _getenv(name) ? malloc((env_len + 1) * sizeof(char *))
								: malloc((env_len + 2) * sizeof(char *));

	if (!nv_environ)
	{
		free(nv_entry);
		return (NULL);
	}
	for (i = 0; environ[i]; i++)
	{
		nv_environ[i] = malloc(strlen(environ[i]) + 1);
		if (!nv_environ[i])
		{
			free_array(nv_environ);
			free(nv_entry);
			return (NULL);
		}
		if (strncmp(environ[i], name, strlen(name)) == 0
		&& environ[i][strlen(name)] == '=')
			strcpy(nv_environ[i], nv_entry);
		else
			strcpy(nv_environ[i], environ[i]);
	}
	if (!_getenv(name))
	{
		nv_environ[env_len] = nv_entry;
		nv_environ[env_len + 1] = NULL;
	}
	else
		nv_environ[env_len] = NULL;
	return (nv_environ);
}

/**
 * _setenv - Initializing or modifying a new envir variable
 * @d: to use the flag
 * @name: variable name
 * @value: variable value
 * Return: void
 */
int _setenv(data *d, char *name, char *value)
{
	char **nv_environ;

	if (!name || !value)
		return (-1);

	nv_environ = _nv_environ(name, value);
	if (!nv_environ)
		return (-1);
	environ = nv_environ;
	d->flg_setenv = 1;

	return (0);
}
