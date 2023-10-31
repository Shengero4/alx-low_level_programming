#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * allocate_buffer - Allocates memory for a data buffer.
 * @source_file: The name of the source file.
 *
 * Return: A pointer to the allocated buffer.
 */
char *allocate_buffer(char *source_file)
{
	char *data_buffer;

	data_buffer = malloc(sizeof(char) * 1024);

	if (data_buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Cannot allocate memory for buffer.\n");
		exit(99);
	}

	return (data_buffer);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int close_status;

	close_status = close(fd);

	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to close file descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int source_fd, dest_fd, bytes_read, bytes_written;
	char *data_buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO,
				"Invalid number of arguments. Usage: cp file_from file_to\n");
		exit(97);
	}

	data_buffer = allocate_buffer(argv[1]);
	source_fd = open(argv[1], O_RDONLY);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		bytes_read = read(source_fd, data_buffer, 1024);
		if (bytes_read == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Unable to read from the source file %s\n", argv[1]);
			free(data_buffer);
			exit(98);
		}

		bytes_written = write(dest_fd, data_buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Unable to write to the destination file %s\n", argv[2]);
			free(data_buffer);
			exit(99);
		}
	} while (bytes_read > 0);

	free(data_buffer);
	close_file(source_fd);
	close_file(dest_fd);

	return (0);
}
