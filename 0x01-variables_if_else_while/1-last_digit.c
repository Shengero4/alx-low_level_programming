#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Entry point
 * Return: 0 always
 */

int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 5)
	{
		printf("%d is greater than 5\n", n);
	}
	if (n == 0)
	{
		printf("%d is 0\n", n);
	}
	if (n < 6 && n != 0)
	{
		printf("%d is less than 6 and not 0\n", n);
	}
	return (0);
}
