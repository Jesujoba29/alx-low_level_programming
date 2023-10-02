#include "main.h"

/**
 * create_file - File is created.
 *
 * @filename: The name of file to be created
 * @text_content: String to write to the file
 * Return: If succeeds return 1 if  not return -1
 */
int create_file(const char *filename, char *text_content)
{
	int jb, y, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
		len++;
	}

	jb = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	y = write(jb, text_content, len);

	if (jb == -1 || y == -1)
		return (-1);
	close(jb);

	return (1);
}
