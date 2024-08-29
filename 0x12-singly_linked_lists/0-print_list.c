#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 * print_list - prints all the elements of a linked list
 * @h: pointer
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
