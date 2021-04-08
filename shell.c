#include "shell.h"

int main(int argc, char **argv, char **env)
{
	char *buffer;
	char **command_array;
	size_t size;
	ssize_t line_size;
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

		size = 0;
		buffer = NULL;

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}

	exit(0);
}
