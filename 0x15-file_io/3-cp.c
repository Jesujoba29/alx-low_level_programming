#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void close_file(int jb);
char *create_buffer(char *file);

/**
 * create_buffer - 1024 byte allocated
 * @file: File in which byte are allocated
 *
 *  Return: To the pointer of the allocated byte
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closed file
 * @jb: A file description meant to be code
 */
void close_file(int jb)
{
	int j;

	j = close(jb);

	if (j == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close jb %d\n", jb);
		exit(100);
	}
}

/**
 * main - Duplicate the content of a file to the other
 * @argc: Argument supplied to the content
 * @argv: Pointer to the argument
 *
 * Return: if success return 0
 *
 * Description: The argument is inacurate - exit code 97.
 * The file_from doesnt exist or cant be read  - exit code 98.
 * The file_to cant be written nor created then  - exit code 99.
 * The file_to cant be created nor written - exit code 99.
 */
int main(int argc, char *argv[])
{
	int from, to, c, d;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	c = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || c == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		d = write(to, buffer, c);
		if (to == -1 || d == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		c = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (c > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}


