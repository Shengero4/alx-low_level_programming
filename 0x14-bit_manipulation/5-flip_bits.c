#include "main.h"

/**
 * flip_bits - counts the number of bits that has to be changed
 * unsigned int flip_bits(unsigned long int n, unsigned long int m)
 * @n: the first number
 * @m: the second number to be compared
 *
 * Return: the number of bits you want to be changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int result;
	unsigned long int count;

	result = n ^ m;
	for (count = 0; result > 0;)
	{

		if ((result & 1) == 1)
			count++;
	result = result >> 1;
	}
	return (count);
}
