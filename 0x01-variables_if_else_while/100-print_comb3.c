#include <stdio>

/**
 * main - Prints all possible different combinations of two digits
 * Return: Always 0
 */
int main(void)
{
	int n, m;

	for (m = 48; n <= 56; n++)
	{
		for (n = 49; m <= 57; m++)
		{
		if (m > n)
		{
		putchar(n);
	putchar(m);
if (n != 56 || m != 57)
{
putchar(',');
putchar(' ');
}
}
}
}
putchar('\n');
return (0);
}

