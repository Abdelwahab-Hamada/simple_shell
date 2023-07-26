#include "main.h"

/**
 * hsh - main shell loop
 * @fd: file discraptor
 * @av: program name
 * @env: environ
 *
 * Return: 0 on success, 1 on error, or error code
 */
void hsh(int fd, char *av, char **env)
{
	ssize_t r = 0;
	size_t linesize = 0;
	char *cmd;

	while (r != -1)
	{
		if (isatty(STDIN_FILENO) && fd >= 2)
			write(1, "$ ", 2);
		r = getline(&cmd, &linesize, stdin);

		if (r != -1)
		{
			cmd = strtok(cmd, "\n");
			tokenize(cmd);
			fork_hsh(env, av);
		}
	}
}

/**
 * fork_hsh - fork shell
 * @env: environment
 * @argv0: program name
 *
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
