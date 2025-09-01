#include "main.h"
#include <unistd.h>

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += write(1, "-", 1);
		/* fix for INT_MIN */
		num = (unsigned int)(-(long)n);
	}
	else
	{
		num = (unsigned int)n;
	}

	if (num / 10)
		count += print_number(num / 10);

	count += write(1, &((char){(num % 10) + '0'}), 1);

	return (count);
}

