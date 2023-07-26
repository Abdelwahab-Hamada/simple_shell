#include "main.h"

/**
 * read_line - get input from user
 *
 * Return: cmd
 */
char *read_line()
{
	char *cmd = NULL;
	size_t cmdsize = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	read = getline(&cmd, &cmdsize, stdin);

	if (read == -1)
	{
		free(cmd);
		return (NULL);
	}

	if (*cmd == '\n' || (_strspn(cmd, " \t\r\n") == _strlen(cmd)))
	{
		free(cmd);
		return (read_line());
	}

	if (cmd[_strlen(cmd) - 1] != '\n')
	{
		cmdsize += 2;
		cmd = (char *)realloc(cmd, cmdsize);
		if (cmd == NULL)
		{
			free(cmd);
			perror("Failed to allocate");
			return (NULL);
		}
		cmd[_strlen(cmd) - 1] = '\0';
	}

	return (cmd);
}

