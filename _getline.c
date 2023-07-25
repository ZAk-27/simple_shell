#include "main.h"

/**
 * _getline_eq - getline eq function
 * @lineptr: inputing string
 * @n: int to be input
 * Return: int
 */
int _getline_eq(char **lineptr, size_t *n)
{
	if (*lineptr == NULL || *n == 0)
	{
		*n = 126;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	return (0);
}

/**
 * _getline - reading file input
 * @lineptr: inputing string
 * @n: int input
 * @stream: FILE input
 * Return: ssize_t
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t bytesRead = 0;
	size_t loc = 0, nvSize;
	static char buf[READ_BUF_SIZE];
	static size_t bufSize, bufLoc;
	char *nvBuffer;

	if (lineptr == NULL || n == NULL || stream == NULL
		|| _getline_eq(lineptr, n) == -1)
		return (-1);
	while (1)
	{
		if (bufLoc >= bufSize)
		{
			bytesRead = read(stream->_fileno, buf, READ_BUF_SIZE);
			if (bytesRead <= 0 && loc == 0)
				return (-1);
			else if (bytesRead <= 0)
				break;
			bufSize = bytesRead;
			bufLoc = 0;
		}
		if (loc >= *n - 1)
		{
			nvSize = *n * 2;
			nvBuffer = realloc(*lineptr, nvSize);
			if (nvBuffer == NULL)
				return (-1);
			*lineptr = nvBuffer;
			*n = nvSize;
		}
		(*lineptr)[loc++] = buf[bufLoc++];
		if ((*lineptr)[loc - 1] == '\n')
			break;
	}
	(*lineptr)[loc] = '\0';
	return (loc);
}
