#include "main.h"

/**
 * set_bit - set bit of a number to 1
 *
 * @n: number to check bits in
 * @index: index to check bit
 *
 * Return: value of the bit or 0 if there is error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int  mask;

	if (index > sizeof(unsigned int) * 8)
		return (0);
	mask = 1;
	mask = mask << index;
	*n = ((*n) | mask);
	return (1);
}
