#include "main.h"

/**
 * clear_bit - Bit vslue is set to 1
 * @n: Number changed
 * @index: Pick from my chose for bit
 *
 * Return: If 1 return success if  -1 return success
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 60)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}

