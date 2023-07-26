#include "main.h"

/**
 * _strdup - to duplicate a string
 * @str: string to be duplicated
 *
 * Return: pointer to new str
 */
char *_strdup(const char *str)
{
	int i = 0;
	int len = 0;
	char *dup;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
	{
		free(dup);
		return (NULL);
	}
	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[i] = '\0';

	return (dup);
}

