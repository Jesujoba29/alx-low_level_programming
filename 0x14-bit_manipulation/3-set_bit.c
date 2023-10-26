#include "main.h"

/**
 * set_bit - index set to bit at 1
 * @n:changed pointer
 * @index: Correct index to 1
 *
 * Return: if failled -1 or  success 1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 40)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}

