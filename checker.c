#include "main.h"

/**
 * check_cmd - check if path
 * @cmd: command
 *
 * Return: 1 | 0
 */
int check_cmd(char *cmd)
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
		perror(token_pair.path);
		return (0);
	}

	return (1);
}

