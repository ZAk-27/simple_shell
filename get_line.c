#include "main.h"

/**
 * _getline_hlpr - getline hlpr function
 * @lineptr: string input
 * @n: int input
 * Return: int
 */
int _getline_hlpr(char **lineptr, size_t *n)
{
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	return (0);
}

/**
 * _getline - reaing  FILE input
 * @lineptr: string input
 * @n: int input
 * @stream: FILE to input
 * Return: ssize_t
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t bytesRead = 0;
	size_t loc = 0, nvSize;
	static char buf[READ_BUF_SIZE];
	static size_t bufSize, bufloc;
	char *nvBuffer;

	if (lineptr == NULL || n == NULL || stream == NULL
		|| _getline_hlpr(lineptr, n) == -1)
		return (-1);
	while (1)
	{
		if (bufloc >= bufSize)
		{
			bytesRead = read(stream->_fileno, buf, READ_BUF_SIZE);
			if (bytesRead <= 0 && loc == 0)
				return (-1);
			else if (bytesRead <= 0)
				break;
			bufSize = bytesRead;
			bufloc = 0;
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
		(*lineptr)[loc++] = buf[bufloc++];
		if ((*lineptr)[loc - 1] == '\n')
			break;
	}
	(*lineptr)[loc] = '\0';
	return (loc);
}
