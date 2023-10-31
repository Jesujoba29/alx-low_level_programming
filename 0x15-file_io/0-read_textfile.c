#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Prints a letter and read file text
 * @filename: The filename
 * @letters: Printed numbers letters
 *
 * Return: Printed letters number if failed return o
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t a;
	ssize_t b;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	b = read(fd, buf, letters);
	a = write(STDOUT_FILENO, buf, b);

	free(buf);
	close(fd);
	return(a);
}

