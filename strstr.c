#include "main.h"

/**
 * _strstr - find str in str
 * @str1: string to search in
 * @str2: string to search
 *
 * Return:1 | 0
 */
int _strstr(char *str1, char *str2)
{
	while (*str1)
	{
		while (*str1 && *str2 && *str1 == *str2)
		{
			str1++;
			str2++;
		}

		if (!*str2)
			return (1);
		break;
	}

	return (0);
}

