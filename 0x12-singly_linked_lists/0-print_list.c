#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints elements of a linked list
 * @h: pointer to the list_t
 *
 * Return: nodes
 */
size_t print_list(const list_t *h)
{
	size_t c = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %c\n", h->len, h->str);
		h = h->next;
		c++;
	}

	return (c);
}
