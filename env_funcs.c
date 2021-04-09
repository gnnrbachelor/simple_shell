#include "shell.h"

char * _getenv(const char *name)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char *env_var = NULL;
	char *value = (char *)malloc(10000);

	while (environ[i])
	{
		if (strncmp(name, environ[i], strlen(name)) == 0)
		{
			env_var = strdup(environ[i]);
			while (env_var[j] != '=')
				j++;
			j++;

			while (env_var[j])
			{
				value[k] = env_var[j];
				j++;
				k++;
			}
		}

		i++;
	}
	return (value);
}
