#include "lists.h"

/**
 * pop_listint -  deletes the head node of a listint_t 
 * @head: double pointer
 *
 * Return: head node’s data
 */
int pop_listint(listint_t **head)
{
	listint_t *store;
	int num;

	if (!head || !*head)
		return (0);

	num = (*head)->n;
	store = (*head)->next;
	free(*head);
	*head = store;

	return (num);
}
