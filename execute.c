#include "shell.h"

/**
 * execute - function to execute input command
 * @command_array: input command
 * @buffer: buffer allocated for input command
 */

void execute(char **command_array, char *buffer)
{
	pid_t pid;
	char *path_command;
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
			execve(command_array[0], command_array, NULL);
		}
		else if (_strcmp(command_array[0], "exit") == 0)
		{
			wait(&status);
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		else
		{
			path_command = check_dir(command_array);
			execve(path_command, command_array, NULL);
		}
	}
	else
	{
		wait(&status);
		free(buffer);
	}
}
