#include "main.h"

/**
 *_puts - to print string
 *@str: string to print
 *:
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 *_putchar - to print one character
 *@c: character to print
 *
 *Return: 1 | -1
 */
int _putchar(char c)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buffer[i++] = c;
	return (1);
}

/**
 * _print - to ease displaying str
 * @str: string to print
 *
 */
void _print(char *str)
{
	_puts(str);
	_putchar('\n');
	_putchar(BUF_FLUSH);
}
