#include "shell.h"

/**
 * _realloc - function reallocates a memory
 * @ptr: a pointer to the memory previously allocated
 * @new_size: new size in bytes of the allocated space for ptr
 * Return: pointer or null
 */
void *_realloc(void *ptr, unsigned int new_size)
{
	void *newsp;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	newsp = malloc(new_size);
	if (newsp == NULL)
	{
		return (NULL);
	}
	free(ptr);
	return (newsp);
}
