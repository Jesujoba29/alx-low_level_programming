#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
* create_buffer - 1024 bytes for a buffer.
* @file: The file storing the work
*
* Return: Allocated newly buffer pointer
*/

	char *create_buffer(char *file)
	{
		char *buffer;

		buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
	dprintf(STDERR_FILENO,
	"Error: Can't write to %s\n", file);
	exit(99);
	}
	return (buffer);
	}

/**
*close_file - Closes file descriptors.
* @fd: The file descriptor to be closed.
*
* Return: if success 1 if not 0
*/
	void close_file(int fd)
	{
		int a;

		a = close(fd);
		if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
	}
	}
/**
* main - Duplicate file content to the other
* @argc: Argument number supplied in the code
* @argv: pointers in the program.
*
* Return: 0 on success.
*
* Description: Argument count is incorrec - exit code 97.
* If the file 'file_from' cannot be found or is unreadable - exit code 98.
* In case 'file_to' cannot be generated or written to - exit code 99.
* If not possible to complete the closing of file - exit code 100.
*/
int main(int argc, char *argv[])
{
	int from, to, a, b;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	a = read(from, buffer, 1024);
		to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {

	if (from == -1 || a  == -1)
	{
		dprintf(STDERR_FILENO,
		"Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	b = write(to, buffer, a);
	if (to == -1 || b == -1)
	{
		dprintf(STDERR_FILENO,
		"Error: Can't write to %s\n", argv[2]);
		free(buffer);
		exit(99);
	}

	a = read(from, buffer, 1024);
	to = open(argv[2], O_WRONLY | O_APPEND);
	} while (a > 0);
	free(buffer);
	close_file(from);
	close_file(to);
	return (0);
	}
