#include "shell.h"
/**
 * main - main function of shell program
 * @argc: argument count
 * @argv: argument array
 * @env: environmental variable
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	char *buffer;
	char **command_array;
	size_t size;
	ssize_t line_size;
	pid_t pid;
	struct stat fstat;
	(void)argv;
	(void)argc;
	(void)env;

	buffer = NULL;

	write(STDOUT_FILENO, "$ ", 2);
	while ((line_size = getline(&buffer, &size, stdin)) < 1024)
	{
		command_array = tokenize(buffer);
		pid = fork();
		if (pid == -1)
			perror("Error\n");

		if (pid == 0)
		{
			if (stat(command_array[0], &fstat) == 0)
			{
				execve(command_array[0], command_array, NULL);
/* need to find the way to add "$ " behind stat */
			}
			else
			{
				perror("Problem\n");
				write(STDOUT_FILENO, "$ ", 2);
			}
		}
	}
	free_token(command_array);
        exit(0);
}
