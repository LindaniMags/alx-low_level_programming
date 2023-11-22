#include "lists.h"

/**
 * sum_listint - returns the sum of all the data
 * @head: initial node
 *
 * Return: sum
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *store = head;

	while (store)
	{
		sum += store->n;
		store = store->next;
	}

	return (sum);
}
