#include <stdio>

/**
 * main - Prints all possible different combinations of two digits
 * Return: Always 0
 */
int main() {
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            // Print tens digit
            putchar(i + '0');
            // Print units digit
            putchar(j + '0');

            // Check if it is not the last combination
            if (!(i == 8 && j == 9)) {
                // Print separator
                putchar(',');
                putchar(' ');
            }
        }
    }

    // Print a new line at the end
    putchar('\n');

    return 0;
}
