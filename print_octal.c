#include "main.h"

/**
 * print_octal - prints an unsigned int in octal
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_octal(unsigned int n)
{
	int count = 0;

	if (n / 8)
		count += print_octal(n / 8);

	count += _putchar((n % 8) + '0');

	return (count);
}
