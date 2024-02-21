#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the alphabet in lowercase followed by a new line using the putchar function only twicel.
 *
 * Return: Always 0 (Success)
 */

int main (void)
{
	char c;
	/* Print lowercase alphabet using putchar */

	for (c = 'a'; c <= 'z'; ++c)
	{
		putchar(c);
	}

	/* Print a newline using putchar */
	putchar('\n');

	return (0);
}
