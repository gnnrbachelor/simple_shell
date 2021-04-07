#include "shell.h"

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)), char **env __attribute__((unused)))
{
	char *buffer;
	char **command_array;
	size_t size;
	ssize_t line_size;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		line_size = getline(&buffer, &size, stdin);
		if (line_size == -1)
			return (-1);

		command_array = token_test(buffer);
		if (command_array == NULL)
			return (-1);
		else
			execute(command_array);

		line_size = 0;
		buffer = NULL;

	}

	exit(0);
}
