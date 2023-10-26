#include "main.h"

/**
 * get_bit - Bit value  return back to decimal number
 * @n: check for numbers
 * @index: Just Bit
 *
 * Return: The Bit component end results
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 50)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}

