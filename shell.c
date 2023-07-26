#include "main.h"

/**
 * hsh - simple shell
 * @ac: args count
 * @argv: args vector
 *
 */
void hsh(int ac, char **argv)
{
	char *cmd = NULL;
	int run = 1;
	char **toks;

	do {
		cmd = read_line(ac, argv);

		if (cmd == NULL)
		{
			free(cmd);
			break;
		}
		toks = tokenize(cmd);
		run = exec_toks(toks);

		free(cmd);
		free_ptr(toks);

	} while (run);
}

