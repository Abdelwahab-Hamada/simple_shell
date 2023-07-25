#include "main.h"

/**
* prompt - prints $ to let user know the program is
* ready to take their input
* prints the prompt if the shell is in interactive mode
* yes
*/
void prompt(void)
{
        if (isatty(STDIN_FILENO))
                write(STDERR_FILENO, "$ ", 2);
}
