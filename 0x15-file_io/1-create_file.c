#include "main.h"
/**
 * create_file - Created file
 * @filename: The filename.
 * @text_content: File content writing in the file
 *
 * Return: If success return 1 , if  fail return -1
 */

int create_file(const char *filename, char *text_content)
{
	int jb, a, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
		len++;
	}

	jb = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	a = write(jb, text_content, len);

	if (jb == -1 || a == -1)
		return (-1);
	close(jb);
	return (1);
}
