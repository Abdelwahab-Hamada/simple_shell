#include "main.h"

/**
 * hsh - shell
 *
 * Return:
 */
void hsh(void)
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
			break;
		if (numchars != EOF && lineptr[0] != '\n' && check_cmd(lineptr))
			fork_hsh();
	}

	free(lineptr);
}

/**
 * fork_hsh - fork shell
 *
 * Return:
 */
void fork_hsh(void)
{
	pid_t child_pid;
	char *env[] = {NULL};
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

