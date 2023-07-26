#include "main.h"

/**
 * check_cmd - check if path
 * @cmd: command
 * @argv0: program name
 *
 * Return: 1 | 0
 */
int check_cmd(char *cmd, char *argv0)
{
	int fd = 2;

	tokenize(cmd);

	if (!_strstr(token_pair.path, "/bin/"))
	{
		char *path = malloc(_strlen("/bin/") + _strlen(token_pair.path) + 1);

		_strcat(path, "/bin/");
		_strcat(path, token_pair.path);

		token_pair.path = path;
	}

	fd = open(token_pair.path, O_RDONLY);

	if (fd == -1)
	{
		perror(argv0);
		return (0);
	}

	return (1);
}

