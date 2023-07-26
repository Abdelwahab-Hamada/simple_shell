#include "main.h"

/**
 * add_node_tail - add node in last node
 * @head: head ptr
 * @str: strig
 * @i: index
 *
 * Return: node
 */
ll_t *add_node_tail(ll_t **head, const char *str, int i)
{
	ll_t *new_node, *node;

	if (head == NULL)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(ll_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(ll_t));
	new_node->i = i;

	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

