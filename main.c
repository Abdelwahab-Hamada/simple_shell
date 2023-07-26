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

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);

		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
				perror(argv[0]);
				exit(127);
			return (EXIT_FAILURE);
		}
	}
	hsh(env, argv[0], fd);
	return (EXIT_SUCCESS);
}
