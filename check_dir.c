#include "shell.h"

char *check_dir(char **command_array)
{
	char **dir_tokens;
	char *env_path;
	char *matched = NULL;
	struct stat check;
	int i = 0;

	env_path = _getenv("PATH");
	dir_tokens = dir_tokenize(env_path);
	while (dir_tokens[i] != NULL)
	{
		dir_tokens[i] = cmd_to_path(dir_tokens[i], command_array[0]);

		if (stat(dir_tokens[i], &check) == 0)
		{
			matched = strdup(dir_tokens[i]);
			return (matched);
		}
		i++;
	}
	return (NULL);
}
