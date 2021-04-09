#include "shell.h"

int dir_num(char * env_path)
{
	int i = 0;
	int count = 0;

	while (env_path[i])
	{
		if (env_path[i] == ':')
			count++;

		i++;
	}
	count++;
	return (count);
}

char * _getenv(const char *name)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int size = 0;
	char *env_var = NULL;
	char *value = NULL;

	while (environ[i])
	{
		if (strncmp(name, environ[i], strlen(name)) == 0)
		{
			env_var = strdup(environ[i]);
			while (env_var[j] != '=')
				j++;
			j++;
			size = j;
			while (env_var[size])
				size++;
			value = malloc(sizeof(char) * size);
			if (value == NULL)
				return (NULL);

			while (env_var[j])
			{
				value[k] = env_var[j];
				j++;
				k++;
			}
			return (value);
		}
		i++;
	}
	return (NULL);
}

char **dir_tokenize(char *paths)
{
	char **dir_tokens = NULL;
	char *dir = NULL;
	int size = 0;
	int i = 0;

	size = dir_num(paths);
	dir_tokens = malloc(sizeof(char *) * (size + 1));
	if (!dir_tokens)
		return (NULL);

	dir = strtok(paths, ":");
	while (dir)
	{
		dir_tokens[i] = strdup(dir);
		dir = strtok(NULL, ":");
		i++;
	}
	dir_tokens[i] = "NULL";
	return (dir_tokens);
}

char *cmd_to_path(char *path, char *command)
{
	int path_len = 0;
	int command_len = 0;
	char *new_path;

	path_len = strlen(path);
	command_len = strlen(command);
	new_path = malloc(sizeof(char) * (path_len + command_len + 2));
	if (!new_path)
		return (NULL);
	_strcpy(new_path, path);
	_strcat(new_path, "/");
	_strcat(new_path, command);
	return (new_path);

}
