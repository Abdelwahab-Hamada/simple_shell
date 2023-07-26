#include "main.h"

/**
 * _strspn - calc len of the initial segment of a str
 * @str: string to be checked
 * @substr: segment of str
 *
 * Return: length
 */
size_t _strspn(char *str, char *substr)
{
	size_t str_len, sub_len;

	for (str_len = 0; str[str_len] != '\0'; str_len++)
	{
		for (sub_len = 0; substr[sub_len]; sub_len++)
		{
			if (str[str_len] == substr[sub_len])
				break;
		}
		if (substr[sub_len] == '\0')
			break;
	}

	return (str_len);
}

