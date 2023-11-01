#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: printing character
 *
 * Return: 1 for success -1 for error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
