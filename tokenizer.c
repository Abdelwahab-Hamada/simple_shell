#include "main.h"

/**
 * tokenize - create excutable cmd
 * @cmd: row cmd
 *
 * Return: tokens
 */
char **tokenize(char *cmd)
{
	size_t cmd_size = CMD_SIZE, i = 0;
	char **tokens = malloc(cmd_size * sizeof(char *));
	char *token;

	if (cmd == NULL || tokens == NULL)
	{
		perror("Failed to allocate space");
		free(tokens);
		exit(EXIT_FAILURE);
	}

	token = strtok(cmd, " \n");

	while (token != NULL)
	{
		tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
			free_ptr(tokens);
			perror("Failed to allocate space");
			exit(EXIT_FAILURE);
		}
		i++;
		if (i >= cmd_size)
		{
			cmd_size += CMD_SIZE;
			tokens = _realloc(tokens, cmd_size * sizeof(char *),
					cmd_size * sizeof(char *));
			if (tokens == NULL)
			{
				free_ptr(tokens);
				perror("Failed to allocate space");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \n");
	}
	tokens[i] = NULL;
	return (tokens);
}

