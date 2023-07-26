#include "main.h"

/**
 * main - entry point
 * @ac: args count
 * @argv: args vector
 *
 * Return: 0 on success
 */
int main(int ac __attribute__((unused)), char **argv __attribute__((unused)))
{
	hsh(ac, argv);
	free_ptr(argv);
	return (0);
}

