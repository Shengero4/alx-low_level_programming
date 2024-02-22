#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the alphabet in lowercase, and then
 * in uppercase, followed by a new line.
 *
 * Return: 0 always
 */

int main(void)
{
	char c;
	     /* Print lowercase alphabet using putchar */
	     for (c = 'a'; c <= 'z'; ++c)
	     {
		     putchar(c);
	     }
	/* Print uppercase alphabet using putchar */

	for (c = 'A'; c <= 'Z'; ++c)
	{
		putchar(c);

	}
	/* Print a newline using putchar */
	putchar('\n');

	return (0);
}
