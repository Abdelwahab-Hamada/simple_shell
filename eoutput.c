#include "main.h"

/**
 *_eputs - to print string
 *@str: string to print
 *
 *Return:
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 *_eputchar - to print one character
 *@c: character to print
 *
 *Return: 1 | -1
 */
int _eputchar(char c)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buffer, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buffer[i++] = c;
	return (1);
}

/**
 * _eprint - to ease displaying str
 * @str: string to print
 *
 * Return:
 */
void _eprint(char *str)
{
	_eputs(str);
	_eputchar('\n');
	_eputchar(BUF_FLUSH);
}

