#include "main.h"

/**
 * execdo - used to handl command execution.
 * @cmnd: command to execut
 * @argv: array input of command line arguments
 * Return: error
 */




	/* used to handl command execution */
void execdo(char **argv)
{
	char *cmnd = NULL, *rec_cmnd = NULL;

	if (argv)
	{
	/* getting command */
	cmnd = argv[0];

	/* generate command path then do it to execve */
	rec_cmnd = get_way(cmnd);

	/* executing command via execve */
	if (execve(rec_cmnd, argv, NULL) == -1)
	{
	perror("ERROR:");
	}
	}

}
