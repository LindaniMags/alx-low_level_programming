#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t
 * linked list
 *
 * @head: head
 * @index: index
 * Return: 1 if it succeeded, else -1
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *head_cpy = *head, *head_cpy_cpy;
	unsigned int count = 0;

	if (head_cpy)
		while (head_cpy->prev)
			head_cpy = head_cpy->prev;

	while (head_cpy)
	{
		if (count++ == index)
		{
			if (!--count)
			{
				*head = head_cpy->next;
				if (*head)
					(*head)->prev = NULL;
			}
			else
			{
				head_cpy_cpy->next = head_cpy->next;
				if (head_cpy->next)
					head_cpy->next->prev = head_cpy_cpy;
			}

			free(head_cpy);
			return (1);
		}
		head_cpy_cpy = head_cpy, head_cpy = head_cpy->next;
	}

	return (-1);
}
