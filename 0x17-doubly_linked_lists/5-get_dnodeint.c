#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 *
 * @head: head
 * @index: index of the node, starting from 0
 * Return: nth node, else NULL
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;

	if (head == NULL)
		return (NULL);

	while (head->prev != NULL)
		head = head->prev;

	while (head != NULL)
	{
		if (count == index)
			break;
		head = head->next;
		count++;
	}

	return (head);
}
