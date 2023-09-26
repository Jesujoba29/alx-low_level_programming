#include "lists.h"

/**
 * listint_len - Return element linked
 * @h:List of  type listint_t traverse
 *
 * Return: Total nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}

	return (num);
}

