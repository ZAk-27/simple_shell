#include "main.h"

/**
 * main - init data
 * @argc: input size of @argv
 * @argv: array of command line args to inputed
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	data d;
	(void)argc;
	init_data(&d, argv[0]);
	_exect(&d);

	return (0);
}
