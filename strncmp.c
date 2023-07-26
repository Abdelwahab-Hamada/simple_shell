#include "main.h"

/**
 * _strncmp - compare 2 strs with n
 * @str1: str1
 * @str2: str2
 * @n: integer
 *
 * Return: 0 | 1 | -1
 */
int _strncmp(const char *str1,const char *str2, int n)
{
	int i = 0;

	while (str1[i] && str2[i] && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}

	if (i == n)
		return (0);

	if (str1[i] && !str2[i])
		return (1);
	else if (!str1[i] && str2[i])
		return (-1);
	return (0);
}

