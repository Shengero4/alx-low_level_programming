#include "main.h"
#include <stdlib.h>

/**
 * clear_bit - set the value of a bit t 0
 *
 * @n: pointer to the number
 * @index: position to change bit
 * Return: integer
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int mask;

	mask = 1;
	mask = mask << index;
	if (index > sizeof(n) * 8 || n == NULL)
		return (-1);
	*n &= ~(1 << index);
	return (1);
}

