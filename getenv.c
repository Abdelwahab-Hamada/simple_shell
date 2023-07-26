#include "main.h"

/**
 * _getenv - get value from environ
 * @var: variable name
 *
 * Return: value
 */
char *_getenv(const char *var)
{
	int len = _strlen(var);
	char **env;

	for (env = environ; *env; ++env)
	{
		if (_strncmp(var, *env, len) == 0 && (*env)[len] == '=')
			return (&((*env)[len + 1]));
	}

	return (NULL);
}

