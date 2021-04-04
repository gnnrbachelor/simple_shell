#include "shell.h"

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	char *cmd;

	while (1)
	{
		user_prompt();
		cmd = read_cmd();

		if (!cmd)
			exit(100);

		if (cmd[0] == '\0' || _strcmp(cmd, "\n") == 0)
		{
			free(cmd);
			continue;
		}

		if (_strcmp(cmd, "exit\n") == 0)
		{
			free(cmd);
			break;
		}

		printf("%s\n", cmd);

		free(cmd);
	}

	exit(0);
}
