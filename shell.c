#include "main.h"

/**
 * hsh - shell
 * @env: environment
 * @argv0: is program name
 *
 */
void hsh(char **env, char *argv0, int fd)
{
	char *lineptr;
	size_t linesize = 0;
	ssize_t r = 0;

	while (r != EOF)
	{
		prompt();
		r = getline(&lineptr, &linesize, stdin);

		if (r != -1)
		{
			tokenize(lineptr);
			fork_hsh(env, argv0);
		}
	}

	free(lineptr);
}

/**
 * fork_hsh - fork shell
 * @env: environment
 * @argv0: program name
 */
void fork_hsh(char **env, char *argv0)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(argv0);
		return;
	}
	if (child_pid == 0)
	{
		execve(token_pair.path, token_pair.cmd, env);

		free(token_pair.path);
		free(token_pair.cmd);

		perror(argv0);
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}

