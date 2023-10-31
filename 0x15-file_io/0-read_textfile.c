#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints
 * it to the POSIX standard output.
 * @filename: The name of the file to be read.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters read and printed. 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor, bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	buffer = malloc(letters);
	if (buffer == NULL)
	{
		close(file_descriptor);
		return (0);
	}

	bytes_read = read(file_descriptor, buffer, letters);
	close(file_descriptor);

	if (bytes_read == -1)
	{
		free(buffer);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	free(buffer);

	if (bytes_written == -1 || bytes_written != bytes_read)
		return (0);

	return (bytes_written);
}
