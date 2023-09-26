#include "lists.h"

/**
 * sum_listint - Data sum of  listint_t list
 * @head: NODE in the first list
 *
 * Return: Sum
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}

	return (sum);
}

