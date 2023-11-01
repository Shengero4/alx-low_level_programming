#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * print_error - prints error message to stderr and exits with given code.
 * @code: exit code.
 * @msg: error message to be printed.
 * Return: no return.
 */
void print_error(int code, char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(code);
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t nchars;
	char buffer[1024];

	if (argc != 3)
		print_error(97, "Usage: cp file_from file_to");

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		print_error(98, "Can't read from file");

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
		print_error(99, "Can't write to file");

	while ((nchars = read(file_from, buffer, 1024)) > 0)
	{
		ssize_t nwr = write(file_to, buffer, nchars);

		if (nwr == -1)
			print_error(99, "Can't write to file");
	}

	if (nchars == -1)
		print_error(98, "Can't read from file");

	if (close(file_from) == -1)
		print_error(100, "Can't close file descriptor");

	if (close(file_to) == -1)
		print_error(100, "Can't close file descriptor");

	return (0);
}

