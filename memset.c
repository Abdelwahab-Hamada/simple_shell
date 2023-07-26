#include "main.h"

/**
 * _memset - creste memory space
 * @str: string pointer
 * @c: character
 * @n: count
 *
 * Return: str ptr
 */
char *_memset(char *str, char c, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		str[i] = c;
	return (str);
}

