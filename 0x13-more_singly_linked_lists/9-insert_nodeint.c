#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: double pointer
 * @idx: index
 * @n: data
 *
 * Return: address of new node, else NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int count;
	listint_t *new;
	listint_t *store = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (count = 0; store && count < idx; count++)
	{
		if (count == idx - 1)
		{
			new->next = store->next;
			store->next = new;
			return (new);
		}
		else
			store = store->next;
	}

	return (NULL);
}
