#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "SZell $ ";
	char *lineptr = NULL, *lineptr_cc = NULL;
	size_t n = 0;
	ssize_t chars_nread;
	const char *delim = " \n";
	int nmb_tkns = 0;
	char *tkn;
	int l;

	/* void variables to declare */
	(void)ac;

	/* creating prompt infnite loop */
	while (1)
	{
	_printf("%s", prompt);
	chars_nread = getline(&lineptr, &n, stdin);
	/* verify the getline function failure or use CTRL + D or get EOF  */
		if (chars_nread == -1)
		{
		_printf("exiting SZell..\n");
		return (-1);
		}

	/* space allocated for the lineptr copy */
	lineptr_cc = malloc(sizeof(char) * chars_nread);
		if (lineptr_cc == NULL)
		{
		perror("shw: error allocation memory ");
		return (-1);
		}
	/* lineptr to be copied to lineptr_cc */
	_strcpy(lineptr_cc, lineptr);

	/* string (lineptr) to split to array nd clculte total tkns nums */
	tkn = strtok(lineptr, delim);

		while (tkn != NULL)
		{
		nmb_tkns++;
		tkn = strtok(NULL, delim);
		}
		nmb_tkns++;

	/* Space to allocate to hold the strings array */
	argv = malloc(sizeof(char *) * nmb_tkns);

	/* Tokens to be stored in the argv */
	tkn = strtok(lineptr_cc, delim);

		for (l = 0; tkn != NULL; l++)
		{
		argv[l] = malloc(sizeof(char) * _strlen(tkn));
		_strcpy(argv[l], tkn);

		tkn = strtok(NULL, delim);
		}
		argv[l] = NULL;

	/* command executing */
	execdo(argv);

	}


	/* allocated memory will be free */
	free(lineptr);
	free(lineptr_cc);

	return (0);
}
