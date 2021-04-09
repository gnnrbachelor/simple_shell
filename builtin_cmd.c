#include "shell.h"

/**
 * built_in_cmd - function to execute built-in commands
 * @command_array: input command
 */
void built_in_cmd(char **command_array, char *buffer)
{
	char *spcmd = "exit";
	int i;

	for (i = 0; command_array[i] != NULL; i++)
	{
	}
	if (i == 1 && _strcmp(command_array[0], spcmd) == 0)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
}
