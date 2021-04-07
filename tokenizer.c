#include "shell.h"

int command_count(char *str)
{
	int count = 0;
	int i = 0;
	int boool = 0;

	while (str[i])
	{
		if (str[i] == ' ')
			boool = 0;
		else if (boool == 0)
		{
			count++;
			boool = 1;
		}
		i++;
	}
	return (count);
}


char **tokenize(char *str)
{
	char *token = NULL;
	char **token_col = NULL;
	int length = 0;
	int i = 0;

	str[strlen(str) - 1] = '\0';
	length = command_count(str);
	if (length == 0)
		return (NULL);

	token_col = malloc((sizeof(char *)) * (length + 1));
	if (!token_col)
		return (NULL);

	token = strtok(str, " ");
	while (token)
	{
		token_col[i] = malloc(strlen(token) + 1);
		if (token_col[i] == NULL)
			return (NULL);
		strncpy(token_col[i], token, strlen(token) + 1);
		token = strtok(NULL, " ");
		i++;
	}
	token_col[i] = NULL;
	return (token_col);
}

