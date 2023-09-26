#include "lists.h"

/**
 * get_nodeint_at_index - Function return nth node
 * @head: Linked list for head node
 * @index: Node starting at 0
 *
 * Return: Null does not exists if Null
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	return (temp ? temp : NULL);
}

