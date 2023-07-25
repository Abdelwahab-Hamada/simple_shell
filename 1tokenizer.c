#include "main.h"

/**
 * tokenize - tokenize command
 * @cmd: command
 *
 */
void tokenize(char *cmd)
{
        char **token = NULL;
        int mlinesize = 1;
        size_t i = 0;
        char *lineptr = strtok(cmd, " ");

        while (*cmd)
        {
                mlinesize++;
                cmd++;
        }

        token = malloc(sizeof(char *) * (mlinesize + 1));

        while (lineptr)
        {
                token[i++] = lineptr;
                lineptr = strtok(NULL, " ");
        }

        token[i] = NULL;

        token_pair.path = token[0];
        token_pair.cmd = token;
}
