#include "shell.h"

/**
 * no_file - fuction to write error message
 * @cmd: input command that triggers error message
 * @argv: argument array
 */
void no_file(char *cmd, char **argv)
{
	char *buffer = NULL;
	char *err = ": command not found\n";
	int cmd_len = 0;
	int err_len = 0;
	int argv_len = 0;
	int bufsize = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	cmd_len = _strlen(cmd);
	err_len = _strlen(err);
	argv_len = _strlen(argv[0]);

	bufsize = cmd_len + err_len + (argv_len + 2);

	buffer = malloc(sizeof(char) * bufsize);
	if (!buffer)
		return;

	for (i = 0; i < bufsize; i++)
	{
		while (i < argv_len)
		{
			buffer[i] = argv[0][i];
			i++;
		}
		if (i == argv_len)
		{
			buffer[i] = ':';
			buffer[++i] = ' ';
		}
		else if (j < cmd_len)
			buffer[i] = cmd[j++];
		else if (k < err_len)
			buffer[i] = err[k++];
	}
	write(STDOUT_FILENO, buffer, bufsize);
	free(buffer);
}
