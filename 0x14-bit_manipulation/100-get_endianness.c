#include "main.h"

/**
 * get_endianness - check the system endianness
 *
 * Return: 0 big endian or 1 for small endian
 */
int get_endianness(void)
{
	int a = 1;
	int b;

	b = (int) (((char *)&)[0]);
	return (b);
}

