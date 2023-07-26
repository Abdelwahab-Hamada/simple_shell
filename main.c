#include "main.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 * @env: environ
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av, char **env)
{
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
                perror(av[1]);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
	}
	hsh(fd, av[1], env);
	return (EXIT_SUCCESS);
}
