#include "../shell.h"

int main(void)
{
	char *str = "This is a test.";
	char **tokens = NULL;

	tokens = tokenize(str);
	return (0);
}
