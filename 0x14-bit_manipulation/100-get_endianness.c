#include "main.h"

/**
 * get_endianness - Supervisethe type of endianness
 *
 * Return: 0 if it big endain while 1 if little
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}

