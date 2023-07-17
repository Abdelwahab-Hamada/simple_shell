#include "main.h"

/**
 * _strcat - to concatinate two strings
 * @dest: destination string
 * @src: source string
 *
 */
void _strcat(char *dest, char *src)
{
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

