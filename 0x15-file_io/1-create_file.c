#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * create_file - creastes a file with the given content.
 * @filename: name of the file to create
 * @text_content: contente to write to the filel
 *
 * Return: 1 if failure
 */

int create_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written, length = 0;

	if (filename == NULL)
		return (-1);


	if (file_descriptor == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length] != '\0')
			length++;

		if (bytes_written == -1 || bytes_written != length)
		{

			return (-1);
		}
	}

	return (1);
}
