#include "main.h"

/**
 * start_process - start a process
 * @d: inputing data struct
 * Return: void
 */

void process_start(data *d)
{
	pid_t child_pid = fork();
	int status = 0;

	if (child_pid == -1)
		goto free;
	if (child_pid == 0 && execve(d->av[0], d->av, NULL) == -1)
		goto free;
	else if (wait(&status) == -1)
		goto free;
	if (WIFEXITED(status))
		d->last_status = WEXITSTATUS(status);
	return;
free:
	perror(d->shell_cr);
	free_array(d->av);
	free(d->cmd);
	exit(EXIT_FAILURE);
}

/**
 * signit_hand - function handler function
 * @signal: int inputd
 * Return: void
 */

void signit_hand(int signal)
{
	/*const char prompt[] = PROMPT;*/
	(void)signal;
	exit(EXIT_FAILURE);
	/*_printf(prompt);*/
}

/**
 * _exect - command executing
 * @d: data struct inputing
 * Return: void
 */

void _exect(data *d)
{
	const char prompt[] = PROMPT;

	signal(SIGINT, signit_hand);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_printf(prompt);

		read_cmd(d);
		if (_strlen(d->cmd) != 0)
		{
			split(d, " ");
			if (!exec_bltn(d))
			{
				_which(d);
				if (access(d->av[0], F_OK) == -1)
				{
					perror(d->shell_cr);
				}
				else
				{
					process_start(d);
				}
			}
			free_array(d->av);
		}
		free(d->cmd);
	}
}
