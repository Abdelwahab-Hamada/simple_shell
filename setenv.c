#include "main.h"

/**
 * set_env - set env
 *
 * Return: node
 */
ll_t *set_env(void)
{
	ll_t *node = NULL;

	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_tail(&node, environ[i], 0);

	return (node);
}

