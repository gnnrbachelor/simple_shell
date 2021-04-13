#include "shell.h"

void no_file(char *cmd)
{
	char *buffer = NULL;
	char *err = ": No such file or directory\n";
	int cmd_len = 0;
	int err_len = 0;
	int bufsize = 0;
	int i = 0;
	int j = 0;

	cmd_len = _strlen(cmd);
	err_len = _strlen(err);

	bufsize = cmd_len + err_len;

	buffer = malloc(sizeof(char) * bufsize);
	if (!buffer)
		return;

	for (i = 0; i < bufsize; i++)
	{
		if (i < cmd_len)
			buffer[i] = cmd[i];
		else
			buffer[i] = err[j++];
	}
	write(STDOUT_FILENO, buffer, bufsize);
	free(buffer);


}
