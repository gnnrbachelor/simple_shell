#include "shell.h"

int main(int argc, char **argv, char **env)
{
	char *buffer;
	char **command_array;
	size_t size;
	ssize_t line_size;
	pid_t pid;
	(void)argv;
	(void)argc;
	(void)env;

	buffer = NULL;

	write(STDOUT_FILENO, "$ ", 2);
	while ((line_size = getline(&buffer, &size, stdin)))
	{
		command_array = tokenize(buffer);
		printf("%s\n", *command_array);

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
	}
	if (pid == 0)
	{
	}
	}

	exit(0);
}
