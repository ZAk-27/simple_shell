#include "main.h"

/**
 * _perror - print it
 * @strl1: name of shell program
 * @strl2: error msg
 * Return: void
 */
void _perror(const char *strl1, const char *strl2)
{
	if (!strl1 || !strl2)
		return;

	while (*strl1)
	{
		write(STDERR_FILENO, strl1, 1);
		strl1++;
	}

	write(STDERR_FILENO, ": ", 2);

	while (*strl2)
	{
		write(STDERR_FILENO, strl2, 1);
		strl2++;
	}
	write(STDERR_FILENO, "\n", 1);
}


/**
 * _trim - leading nd trailing spaces remover
 * @strl: string input
 * Return: void.
 */

void _trim(char *strl)
{
	int i, k, len = _strlen(strl);

	for (i = 0; i < len && (strl[i] == ' ' || strl[i] == '\t'); i++)
		;

	for (k = 0; i < len ; i++, k++)
		strl[k] = strl[i];

	strl[k] = '\0';

	for (i = _strlen(strl) - 1; i > 0 && (strl[i] == ' ' || strl[i] == '\t'); i--)
		strl[i] = '\0';
}


/**
 * _realloc - reallocates a memory block usin free et malloc
 * @ptr: pointer void
 * @nv_size: unsigned int
 *
 * Return: the newly allocated memory
 */
void *_realloc(void *ptr, unsigned int nv_size)
{
	char *p;
	unsigned int i, tr = nv_size, old_size = sizeof(ptr);

	if (old_size == nv_size)
		return (ptr);
	if (ptr == NULL)
		return (malloc(nv_size));

	if (nv_size > old_size)
		tr = old_size;

	if (nv_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	p = malloc(nv_size);

	for (i = 0; i < tr; i++)
		p[i] = ((char *)ptr)[i];
	free(ptr);
	return (p);
}
