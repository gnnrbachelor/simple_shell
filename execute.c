#include "shell.h"

/**
 * execute - function to execute input command
 * @command_array: input command
 * @buffer: buffer allocated for input command
 */

void execute(char **command_array, char *buffer)
{
	pid_t pid;
	struct stat fstat;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Error\n");
	}
	if (pid == 0)
	{
		if (!command_array)
		{
			free(buffer);
		}
		if (stat(command_array[0], &fstat) == 0)
		{
			built_in_cmd(command_array, buffer);
			execve(command_array[0], command_array, NULL);
		}
		else
			perror("Problem\n");
	}
	else
	{
		wait(&status);
		free(buffer);
	}
}
