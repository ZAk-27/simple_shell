#include "main.h"
/**
 * _strdup - returns a pntter to new allocated space in memry,
 * @str: string input
 *
 * Return: pointer
 */
char *_strdup(const char *str)
{
        int i, len = 0;
        char *result;

        if (str == NULL)
                return (NULL);

        while (str[len] != '\0')
                len++;

        result = (char *)malloc((len + 1) * sizeof(char));

        if (result == NULL)
                return (NULL);

        for (i = 0; i <= len; i++)
                result[i] = str[i];

        return (result);
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
 * @c: charachter
 * Return: 1 if  digit 0 otherwise
 */
int _isdigit(int c)
{
        return (c >= '0' && c <= '9');
}

