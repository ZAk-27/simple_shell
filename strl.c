#include "main.h"

/**
 * _strlen - return the numb of chr 
 * @str: string input
 * Return: numb of str in char.
 */

unsigned int _strlen(char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}


/**
 * _strcmp - for comparing two strings.
 * @s1: input const string
 * @s2: input const string
 * Return: the result of the comparison,
 *	as follows:
 *	• 0, if the s1 and s2 are alike
 *	• a negative value if s1 is les than s2
 *	• a positive value if s1 is bigger than s2
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;
	int resu = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			resu = s1[i] - s2[i];
			break;
		}
	}

	return (resu);
}


