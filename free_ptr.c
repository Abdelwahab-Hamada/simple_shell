#include "main.h"

/**
 * free_ptr - free memory recursuivly
 * @ptr: pointer
 *
 */
void free_ptr(char **ptr)
{
	int i;

	if (ptr == NULL)
		return;

	for (i = 0; ptr[i] != NULL; i++)
		free(ptr[i]);
	free(ptr);
}

