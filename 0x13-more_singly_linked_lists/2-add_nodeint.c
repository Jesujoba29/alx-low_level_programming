#include "lists.h"

/**
 * add_nodeint - new node a the begining
 * @head: New Pointer
 * @n: Insert new node
 *
 * Return: New pointer if not Null
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}

