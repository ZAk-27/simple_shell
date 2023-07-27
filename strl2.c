#include "main.h"
/**
 * _strdup - returns a pntter to new allocated space in memry,
 * @strl: string input
 *
 * Return: pointer
 */
char *_strdup(const char *strl)
{
	int i, len = 0;
	char *rslt;

	if (strl == NULL)
		return (NULL);

	while (strl[len] != '\0')
		len++;

	rslt = (char *)malloc((len + 1) * sizeof(char));

	if (rslt == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		rslt[i] = strl[i];

	return (rslt);
}


/**
 * _isnumber - verify if a string is a numb
 * @status: string cheking
 * Return: void
 */
int _isnumber(const char *status)
{
	if (status == NULL || status[0] == '\0')
		return (0);
	while (*status)
	{
		if (!_isdigit(*status))
			return (0);
		status++;
	}
	return (1);
}


/**
 * _isdigit - verify if char is numb
 * @k: charachter
 * Return: 1 if  digit 0 otherwise
 */
int _isdigit(int k)
{
	return (k >= '0' && k <= '9');
}
