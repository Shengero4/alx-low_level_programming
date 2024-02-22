#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: This program prints all the numbers
 * of base 16 in lowercase, followed by a newline.
 *
 * Return:0 always for success
 */

int main(void)
{
	int n;

	for (n = 0; n < 16; ++n)
	{
		putchar(n + '0');
	}

	putchar('\n');
	return (0);
}
