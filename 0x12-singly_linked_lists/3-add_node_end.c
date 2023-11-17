#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a start node at the end of a linked list
 * @head: pointer to pointer
 * @str: start node
 *
 * Return: address, else NULL
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *start;
	list_t *curr = *head;
	unsigned int l = 0;

	while (str[l])
		l++;

	start = malloc(sizeof(list_t));
	if (!start)
		return (NULL);

	start->str = strdup(str);
	start->l = l;
	start->next = NULL;

	if (*head == NULL)
	{
		*head = start;
		return (start);
	}

	while (curr->next)
		curr = curr->next;

	curr->next = start;

	return (start);
}
