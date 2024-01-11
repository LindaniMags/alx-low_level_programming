#include "lists.h"

/**
 * add_dnodeint_end - adds a new_node node at the end of a dlistint_t list
 *
 * @head: head of the list
 * @n: index of the element
 * Return: the address of the new_node element, else NULL
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *t;
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	t = *head;

	if (t != NULL)
	{
		while (t->next != NULL)
			t = t->next;
		t->next = new_node;
	}
	else
	{
		*head = new_node;
	}

	new_node->prev = t;

	return (new_node);
}
