#include "shell.h"

char *read_cmd(void)
{
	size_t bufsize = 0;
	char *buf = NULL, *ptr = NULL, *ptr2 = NULL, ptrlen = 0;

	/* buf = malloc(sizeof(char) * 1024);
	if (buf == NULL)
	{
		free(buf);
		return (NULL);
		} */
	while(getline(&buf, &bufsize, stdin) != 1024)
	{
		int buflen = _strlen(buf);

		if (!ptr)
			ptr = malloc(buflen + 1);
		else
		{
			ptr2 = _realloc(ptr, ptrlen + buflen + 1);
			if (ptr2)
				ptr = ptr2;
			else
			{
				free(ptr);
				ptr = NULL;
			}
		}
		if (!ptr)
		{_puts(_strcat("Error ", strerror(errno)));
			return (NULL);
		}
		_strcpy(ptr + ptrlen, buf);
		if (buf[buflen - 1] == '\n')
		{
			if (buflen == 1 || buf[buflen - 2] != '\\')
				return (ptr);
			ptr[ptrlen + buflen - 2] = '\0';
			buflen -= 2;
			user_prompt();
		}
		ptrlen += buflen;
	}
	return (ptr);
}
