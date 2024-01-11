#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list
 *
 * @head: head of the list
 * Return: none
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *d_list;

	if (head != NULL)
		while (head->prev != NULL)
			head = head->prev;

	while ((d_list = head) != NULL)
	{
		head = head->next;
		free(d_list);
	}
}
