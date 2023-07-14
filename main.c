#include "main.h"

/**
 * main - entry point
 * @argc: args count
 * @argv: args vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	int fd = 2;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);

		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(argv[0]);
				_eprint(": No such file or directory");
				exit(127);
			}
			return (EXIT_FAILURE);
		}
	}
	hsh();
	return (EXIT_SUCCESS);
}

