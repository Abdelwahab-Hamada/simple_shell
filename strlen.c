#include "main.h"

/**
 * _strlen - count string chars
 * @str: string to count
 *
 * Return: string length
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

