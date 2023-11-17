#include <stdlib.h>
#include "lists.h"
#include <string.h>

/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: pointer to pointer
 * @str: string to be added
 *
 * Return: new element, else NULL
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *start;
	unsigned int l = 0;

	while (str[l])
		l++;

	start = malloc(sizeof(list_t));
	if (!start)
		return (NULL);

	start->str = strdup(str);
	start->l = l;
	start->next = (*head);
	(*head) = start;

	return (*head);
}
