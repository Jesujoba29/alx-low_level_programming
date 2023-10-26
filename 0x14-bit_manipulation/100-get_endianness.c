#include "main.h"

/**
 * get_endianness -checks the  type of endianness
 *
 * Return: If 0 retun big endain while 1 if little
 */

int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}

