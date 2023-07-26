#include "main.h"

/**
 * check_cmd - cmd checker
 * @cmd: command to be checked
 *
 * Return: path
 */
char *check_cmd(char *cmd)
{
	char *path = _getenv("PATH");
	size_t cmd_size, path_size;
	char *path_dup, *token;
	char full_path[1024] = "";

	if ((cmd[0] == '/') || (cmd[0] == '.') || (cmd[0] == '~'))
	{
		if (access(cmd, F_OK) == 0)
			return (_strdup(cmd));
	}
	else
	{
		if (path == NULL)
			return (NULL);
		cmd_size = _strlen(cmd);
		path_dup = _strdup(cmd);
		token = strtok(path_dup, ":");

		while (token != NULL)
		{
			path_size = _strlen(cmd);
			if (path_size + 1 + cmd_size >= sizeof(full_path))
			{
				free(path_dup);
				return (NULL);
			}
			_strcpy(full_path, token);
			_strcpy(full_path, "/");
			_strcpy(full_path, cmd);
			if (access(full_path, F_OK) == 0)
			{
				free(path_dup);
				return (_strdup(full_path));
			}
			token = strtok(NULL, ":");
		}
		free(path_dup);
	}
	return (NULL);
}

