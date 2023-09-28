#include "main.h"

/**
 * set_bit - Index set to bit at 1
 * @n:Already changed pointer
 * @index: Set index to 1
 *
 * Return: If failled -1 or  success 1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 40)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}

