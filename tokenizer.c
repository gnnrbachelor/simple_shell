#include "shell.h"

int command_count(char *str)
{
	int count = 0;
	int i = 0;
	int incommand = 0;

	printf("test\n");

	while (str[i])
	{
		if (str[i] != ' ')
			incommand = 1;
		if ((incommand && str[i + 1] == ' ') || (incommand && str[i + 1] == '\0'))
		{
			count++;
			incommand = 0;
		}
		i++;
	}
	return (count);
}

char **token_test(char *str)
{
	char **p;
	char *array[] = { "The quick",
                  "brown fox",
                  "jumps over",
                  "the lazy dog." };
	p = array;

	(void)str;
	printf("token\n");
	return (p);
}


char **tokenize(char *str)
{
	char *token;
	char **token_array;
	unsigned int length = 0;
	int i = 0;

	str[strlen(str) - 1] = '\0';
	length = command_count(str);
	if (length == 0)
		return (NULL);

	token_array = malloc((sizeof(char *)) * (length + 1));
	if (token_array == NULL)
		return (NULL);

	token = strtok(str, " ");
	while (token != NULL)
	{
		token_array[i] = malloc(strlen(token) + 1);
		if (token_array[i] == NULL)
			return (NULL);
		strncpy(token_array[i], token, strlen(token) + 1);
		token = strtok(NULL, " ");
		i++;
	}
	token_array[i] = NULL;
	return (token_array);
}
