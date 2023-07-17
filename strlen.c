#include "main.h"

/**
 * _strlen - string length
 * @str: string
 *
 * Return: length
 */
int _strlen(char *str)
{
	int counter = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		counter++;
		i++;
	}

	return (counter);
}

