#include "lists.h"

/**
 * reverse_listint - Linked list all reversed
 * @head: First node pointer linked lists
 *
 * Return: First node list pointer
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}

	*head = prev;

	return (*head);
}

