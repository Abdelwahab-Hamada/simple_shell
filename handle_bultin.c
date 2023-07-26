#include "main.h"

/**
 * handle_builtin - no needed
 * @tokens: cmd
 *
 */
void handle_builtin(char **tokens)
{
	if (_strcmp(tokens[0], "exit") == 0)
	{
		int status = 0;

		if (tokens[1] != NULL)
			status = _atoi(tokens[1]);
		exit(status);
	}
	else if (_strcmp(tokens[0], "env") == 0)
	{
		penv();
		return;
	}
}

