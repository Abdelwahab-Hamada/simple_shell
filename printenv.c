#include "main.h"

/**
 * penv - print enviroment
 *
 */
void penv(void)
{
	const ll_t *head = set_env();
	char *str;

	while (head)
	{
		str = head->str ? head->str : "(nil)";
		write(1, str, _strlen(str));
		write(1, "\n", 1);
		head = head->next;
	}
}

