#include "main.h"

/**
 * penv - print enviroment variables
 * @env: environmen
 * t
 */
void penv(char **env)
{
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		_print(env[i]);
		i++;
	}
}

