#include "main.h"

/**
 * _atoi - char to int
 * @str: string
 *
 * Return: integer
 */
int _atoi(char *str)
{
	int i = 0;
	int str_len = 1;
	int r_value = 0;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;

	if (str[i] == '+' || str[i] == '-')
		str_len = (str[i++] == '-') ? -1 : 1;

	while (str[i] >= '0' && str[i] <= '9')
		r_value = r_value * 10 + (str[i++] - '0');

	return (r_value + str_len);
}

