#include "lists.h"
#include "stdio.h"

/**
 * print_listint - Print element in listedint 
 * @h:the original head node
 *
 * Return: Total nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		printf("%d\n", h->n);
		num++;
		h = h->next;
	}

	return (num);
}

