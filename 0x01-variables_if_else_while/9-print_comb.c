#include <stdio.h>

/**
 * main -  Entry point
 * Description: A program that prints all possible combinations
 * of single-digit numbers.
 *
 * Return: 0 Always for success
 */

int main(void)
{
	int i;

	for (i = 48; i < 58; i++)
	{
		putchar(i);
		if (i != 57)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
