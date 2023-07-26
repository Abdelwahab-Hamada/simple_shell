#include "main.h"

/**
 * _realloc - to reallocate space in memory
 * @ptr: pointer to space in memory
 * @old_size: no describtion needed
 * @new_size: as above
 *
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, size_t new_size)
{
	char *nu_add, *tmp;
	unsigned int i;

	if (ptr != NULL)
		tmp = ptr;
	else
		return (malloc(new_size));
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (0);
	}
	nu_add = malloc(new_size);
	if (nu_add == NULL)
		return (NULL);
	for (i = 0; i < old_size && i < new_size; i++)
		*(nu_add + i) = tmp[i];
	free(ptr);

	return (nu_add);
}

