#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: this program will print all single didgit
 * numbers of base 10 starting from 0, followed by a newline.
 *
 * Return: 0 always for success
 */

int main(void)

{
	int i;

	for (i = 48; i < 58; i++)
	{
		putchar(i);
	}
	putchar('\n');

	return (0);
}
