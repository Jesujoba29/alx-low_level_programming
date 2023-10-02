#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read and print the content of STDOUT
 * @filename: The name of file to read
 * @letters: number of letters to be read
 * Return: O if number of byte read and printed or -1 if error
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t x;
	ssize_t y;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	return (0);
	buf = malloc(sizeof(char) * letters);
	y = read(fd, buf, letters);
	x = write(STDOUT_FILENO, buf, y);

	free(buf);
	close(fd);
	return (x);
}

