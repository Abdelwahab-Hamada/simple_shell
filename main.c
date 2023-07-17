#include "main.h"

/**
 * main - entry point
 * @argc: args count
 * @argv: args vector
 * @env: environment
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv, char **env)
{
	int fd = 2;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);

		if (fd == -1)
		{
			perror(argv[0]);
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
				exit(127);
			return (EXIT_FAILURE);
		}
	}
	hsh(env);
	return (EXIT_SUCCESS);
}

