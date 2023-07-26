#include "main.h"

/**
 * _strtok - splits string into tokens with a delimiter
 * @string: string to be used
 * @del: delimiter
 *
 * Return: tokenized string
 */
char *_strtok(char *string, const char *del)
{
	char *token;
	static char *flag;

	if (string != NULL)
	{
		flag = string;
	}

	if (flag == NULL || *flag == '\0')
	{
		return (NULL);
	}

	while (*flag != '\0' && strchr_alt(del, *flag) != NULL)
	{
		flag++;
	}

	if (*flag == '\0')
	{
		return (NULL);
	}

	token = flag;
	while (*flag != '\0' && strchr(del, *flag) == NULL)
	{
		flag++;
	}
	if (*flag != '\0')
	{
		*flag = '\0';
		flag++;
	}
	return (token);
}

