#include "main.h"

/**
 * clear_bit -Value of bit set to 1
 * @n: Number replaced
 * @index: SElect from my choice for b
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

