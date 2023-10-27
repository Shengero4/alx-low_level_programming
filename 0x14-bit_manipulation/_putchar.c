#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: characta to print
 *
 * Return: if success 1.
 */
int _putchar(char c)
{
	return(write(1, &c, 1));
}
