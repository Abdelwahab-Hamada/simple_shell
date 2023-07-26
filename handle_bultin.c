#include "main.h"

/**
 * handle_builtin - no needed
 * @tokens: cmd
 * @lineptr: to free
 *
 */
void handle_builtin(char **tokens, char *lineptr)
{
	if (_strcmp(tokens[0], "exit") == 0)
	{
		int status = 1;

		if (tokens[1] != NULL)
			status = _atoi(tokens[1]);
		free(lineptr);
		free_ptr(tokens);
		exit(status);
	}
	else if (_strcmp(tokens[0], "env") == 0)
	{
		return;
	}
}

