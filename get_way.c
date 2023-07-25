#include "main.h"

char *get_way(char *cmnd)
	{
	char *way, *way_cc, *way_tkn, *file_way;
	int cmnd_length, dir_length;
	struct stat buff;

	way = getenv("PATH");

	if (way)
	{
	/* way string to duplicate */
	way_cc = _strdup(way);
	/* Getting command length  */
	cmnd_length = _strlen(cmnd);

	/* separing all path variables nd make directories on */
	way_tkn = strtok(way_cc, ":");

	while (way_tkn != NULL)
	{

	/** Getting directory length*/
	dir_length = _strlen(way_tkn);

	/** memory allocation for storing dir nd comnd names together */
	file_way = malloc(cmnd_length + dir_length + 2);
	/* 2 is added for the slash */

	/** copying dir path nd conctnate the commnd for building path */
	_strcpy(file_way, way_tkn);
	_strcat(file_way, "/");
	_strcat(file_way, cmnd);
	_strcat(file_way, "\0");

	/*  testing existing of faile pathreturn it if ok or trying next directory */
	if (stat(file_way, &buff) == 0)
	{
	/* return = 0 is succes */

	/** free up allocated memory to be freed then return ur file_way */
	free(way_cc);

	return (file_way);
	}
	else
	{

	/** free file_way memory for checking another path way*/
	free(file_way);
	way_tkn = strtok(NULL, ":");

	}

	}

	/** free memory for way_cc if not get any file, return NULL nd free memory */
	free(way_cc);

	/** checking if the file_way already exists */
	if (stat(cmnd, &buff) == 0)
	{
	return (cmnd);
	}


	return (NULL);

	}


	return (NULL);
	}

