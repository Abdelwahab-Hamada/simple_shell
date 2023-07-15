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
		if (numchars == EOF && isatty(STDIN_FILENO))
			_print("");
		if (numchars != EOF && lineptr[0] != '\n')
			fork_hsh(lineptr);
	}

	free(lineptr);
}

/**
 * fork_hsh - fork shell
 *
 * Return:
 */
void fork_hsh(char *lineptr)
{
	pid_t child_pid;
	char *args[] = {NULL, NULL, NULL};
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
		lineptr = strtok(lineptr, "\n");
		args[0] = strtok(lineptr, " ");
		args[1] = strtok(NULL, " ");
		execve(args[0], args, env);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);
}

