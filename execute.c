#include "shell.h"


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
			exit(EXIT_SUCCESS);
		}
		if (stat(command_array[0], &fstat) == 0)
			execve(command_array[0], command_array, NULL);
		else
			perror("Problem\n");
	}
	else
	{
		wait(&status);
		free(buffer);
		exit(EXIT_SUCCESS);
	}

}
