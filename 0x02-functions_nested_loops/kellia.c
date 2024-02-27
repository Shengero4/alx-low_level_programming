#include <stdio.h>

/**
 * main - Entry point
 * Description: this is a random program
 */

int factorial(int n)
{
	int retval = 1;
	while(n! = 1) {
		retval *= n--;
	}
	return retval;
}

int main(void)
{
	int val = factorial(5);
	Printf("%d! = %d\n",5,val);

	printf("%d! = %d\n",4,factorial(4));
	
	return 0;
}
