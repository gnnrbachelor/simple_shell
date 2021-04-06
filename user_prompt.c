#include "shell.h"

void user_prompt(void)
{
	write(STDERR_FILENO, "$ ", 2);
}
