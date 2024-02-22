#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Write a program that prints the alphabet
 * in lowercase, followed by a new line.
 * using putchar with the exception of letter Q and E
 *
 * Return: 0 Always
 */

int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; ++letter)
	{
		if (letter != 'q' && letter != 'e')
		{
			putchar(letter);
		}
	}

	putchar('\n');

	return (0);

}
