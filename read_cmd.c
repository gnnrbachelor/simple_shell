#include "shell.h"

char *read_cmd(void)
{
	char buf[1024];
	char *ptr = NULL;
	char *ptr2 = NULL;
	char ptrlen = 0;

	while(fgets(buf, 1024, stdin))
	{
		int buflen = _strlen(buf);

		if (!ptr)
			ptr = malloc(buflen + 1);
		else
		{
			ptr2 = realloc(ptr, ptrlen + buflen + 1);
			if (ptr2)
				ptr = ptr2;
			else
			{
				free(ptr);
				ptr = NULL;
			}
		}

		if (!ptr)
		{
			fprintf(stderr, "Error %s\n", strerror(errno));
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
