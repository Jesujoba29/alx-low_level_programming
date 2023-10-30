#include "main.h"

/**
 * read_textfile - Prints a letter and read file text
 * @filename: The filename
 * @letters: Printed numbers letters
 *
 * Return: Printed letters number if failed return o
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nr, nw;
	char *buff;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd  == -1)
		return (0);

	buff = malloc(sizeof(char) * (letters));
	if (!buff
		return (0);

	nr = read(fd, buff letters);
	nw = write(STDOUT_FILENO, buff nr);

	close(fd);

	free(buff);

	return (nw);
}

