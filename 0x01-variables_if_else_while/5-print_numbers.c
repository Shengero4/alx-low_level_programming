#include <stdio.h>


/**
 * main - Entry point
 *
 * Description: Program that prints all single digit numbers
 * of base 10 starting from 0 followed by a new line
 * Return: 0 always (for success)
 */

int main(void)
{
	int n;

	for (n = 0; n < 10; ++n)
	{
		putchar(n + '0');
	}

	putchar('\n');
		return (0);

}
