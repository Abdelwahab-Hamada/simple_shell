#include "main.h"

/**
 * hsh - shell
 * @env: environment
 *
 */
void hsh(char **env)
{
	char *lineptr;
	size_t linesize = 0;
	ssize_t numchars = 0;

	while (numchars != EOF)
	{
		prompt();
		numchars = getline(&lineptr, &linesize, stdin);

		if (*lineptr == '\n')
			continue;

		lineptr = strtok(lineptr, "\n");
		if (_strstr(lineptr, "exit"))
			exit(0);
		if (_strstr(lineptr, "env"))
			penv(env);
		if (numchars != EOF && lineptr[0] != '\n' && check_cmd(lineptr))
			fork_hsh(env);
	}

	free(lineptr);
}

/**
 * fork_hsh - fork shell
 * @env: environment
 *
 */
void fork_hsh(char **env)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return;
	}
	if (child_pid == 0)
	{
		execve(token_pair.path, token_pair.cmd, env);

		free(token_pair.path);
		free(token_pair.cmd);

		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}

