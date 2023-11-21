#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list
 * @head: initial node
 * @index: index
 *
 * Return:  nth node, else NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int num = 0;
	listint_t *store = head;

	while (store && num < index)
	{
		store = store->next;
		num++;
	}

	return (store ? store : NULL);
}
