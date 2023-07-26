#include "main.h"

/**
 * hsh - shell
 * @env: environment
 * @argv0: is program name
 *
 */
void hsh(char **env, char *argv0)
{
	char *lineptr;
	size_t linesize = 0;
	ssize_t numchars = 0;

	while (numchars != EOF)
	{
		prompt();
		numchars = getline(&lineptr, &linesize, stdin);

		if (*lineptr == '\n' || *lineptr == ' ' || *lineptr == '\t')
			continue;

		lineptr = strtok(lineptr, "\n");
		if (_strstr(lineptr, "exit"))
			exit(0);
		if (_strstr(lineptr, "env"))
			penv(env);
		if (numchars != EOF && lineptr[0] != '\n' && check_cmd(lineptr, argv0))
			fork_hsh(env, argv0);
		else
			_putchar('\n');
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

