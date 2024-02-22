#include <stdio.h>

/**
 * main - Entry point
 *
 * Desription: this program prints the lowercase alphabet
 * in reverse, followed by new line.
 *
 * Return: 0 always for success
 */

int main(void)

{
	char c;

	for (c = 'z'; c >= 'a'; ++c)
	{
		putchar(c);
	}

	/* Print a newline using putchar */
	putchar('\n');

	return (0);
}
