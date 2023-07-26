#include "main.h"

/**
 * penv - print enviroment
 *
 */
void penv(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(1, *env, strlen(*env));
		write(1, "\n", 1);
		env++;
		free(*env);
	}
	free_ptr(env);
}

