#include "main.h"

/**
 * _strcmp - compare strings
 * @str1: str1
 * @str1: str2
 *
 * Return: 0 | 1 | -1
 */
int _strcmp(char *str1, char *str2)
{
	int len = 0;

	while (str1[len] == str2[len] && str1[len])
		len++;

	if (str1[len] > str2[len])
		return (1);
	if (str2[len] < str2[len])
		return (-1);
	return (0);
}

