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
	int return_value = 0;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;

	if (str[i] == '+' || str[i] == '-')
		str_len = (str[i++] == '-') ? -1 : 1;

	while (str[i] >= '0' && str[i] <= '9')
		return_value = return_value * 10 + (str[i++] - '0');

	return (return_value + str_len);
}

