#include "main.h"
#include <unistd.h>
/**
 * _putchar - REAdline character c to stdio
 * @c: Print Characters
 *
 * Return:1 if successfull
 * Error: Errno set -1 is conceded
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

