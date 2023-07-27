#include "main.h"

/**
 * _strlen - return the numb of chr
 * @strl: string input
 * Return: numb of str in char.
 */

unsigned int _strlen(char *strl)
{
	unsigned int i;

	for (i = 0; strl[i] != '\0'; i++)
		;
	return (i);
}


/**
 * _strcmp - for comparing two strings.
 * @s1: input const strin
 * @s2: input const strin
 * Return: the reslt of the comparison,
 *	as follows:
 *	• 0, if the s1 and s2 are alike
 *	• a negative value if s1 is les than s2
 *	• a positive value if s1 is bigger than s2
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;
	int resl = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			resl = s1[i] - s2[i];
			break;
		}
	}

	return (resl);
}

/**
 * _strncmp - for comparing two strings.
 * @s1: input const strin
 * @s2: input const strin
 * @n: input int
 *
 * Return: returns an int indicating comparision reslt ,
 *	as follows:
 *	• 0, if the s1 and s2 are equal
 *	• a negative value if s1 is les than s2
 *	• a positive value if s1 is bigger than s2
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i;
	int resl = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{

		if (i >= n)
			break;
		if (s1[i] != s2[i])
		{
			resl = s1[i] - s2[i];
			break;
		}
	}

	return (resl);
}

/**
 * _strcpy - copy it to destinat .
 *
 * @desti: input char *
 * @srcl: input const char *
 *
 * Return: char *
 */
char *_strcpy(char *desti, const char *srcl)
{
	int len;

	for (len = 0; srcl[len] != '\0'; ++len)
	{
		desti[len] = srcl[len];
	}
	desti[len] = '\0';
	return (desti);
}

/**
 * _strcat - appends the string,
 * @desti: input string
 * @srcl: input const string
 *
 * Return: void
 */
char *_strcat(char *desti, const char *srcl)
{
	char *rslt = desti;

	while (*desti != '\0')
		desti++;

	while (*srcl != '\0')
	{
		*desti = *srcl;
		desti++;
		srcl++;
	}
	*desti = '\0';

	return (rslt);
}
