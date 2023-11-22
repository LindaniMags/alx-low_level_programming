#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index
 * @head: double pointer
 * @index: index
 *
 * Return: 1 if successful, else -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *store = *head;
	listint_t *count = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(store);
		return (1);
	}

	while (i < index - 1)
	{
		if (!store || !(store->next))
			return (-1);
		store = store->next;
		i++;
	}


	count = store->next;
	store->next = count->next;
	free(count);

	return (1);
}
