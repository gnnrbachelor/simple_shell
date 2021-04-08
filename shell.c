#include "shell.h"

int main(int argc, char **argv, char **env)
{
	char *buffer;
	char **command_array;
	size_t size;
	ssize_t line_size;
/*	pid_t pid;
	struct stat fstat;
	int status; */
	(void)argv;
	(void)argc;
	(void)env;

	buffer = NULL;

	if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

	while ((line_size = getline(&buffer, &size, stdin)))
	{

		command_array = tokenize(buffer);
		execute(command_array, buffer);

/*
		pid = fork();
		if (pid == -1)
		{
			perror("Error\n");
		}
		if (pid == 0)
		{
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
*/

		size = 0;
		buffer = NULL;

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

	}

	exit(0);
}
