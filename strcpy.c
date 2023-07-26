#include "main.h"

/**
 * _strcpy - copy string
 * @des: destination
 * @src: source
 *
 * Return: dest
 */
char *_strcpy(char *des, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		des[i] = src[i];
		i++;
	}

	des[i] = '\0';

	return (des);
}

