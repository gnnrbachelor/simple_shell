#include "shell.h"

void handle_ctrl_c(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n$ ", 3);
}
