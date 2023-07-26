#include "main.h"

/**
 * exec_toks - execute cmd
 * @tokens: cmd
 *
 * Return: 0 || exit fialure
 */
int exec_toks(char **tokens)
{
	int status;
	char *cmd;
	pid_t child;

	if (tokens == NULL)
		return (1);

	handle_builtin(tokens);
	cmd = check_cmd(tokens[0]);
	if (cmd == NULL)
	{
		perror("./hsh");
		return (1);
	}

	child = fork();
	if (child == -1)
	{
		perror("./hsh");
		return (1);
	}
	if (!child)
	{
		if (execve(cmd, tokens, environ) == -1)
		{
			perror("./hsh");
			free(cmd);
			exit(1);
		}
	}
	else
		waitpid(child, &status, 0);

	return (-1);
}

