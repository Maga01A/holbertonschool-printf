#include "main.h"

/**
 * print_string - prints a string
 * @str: string to print
 *
 * Return: number of characters printed
 */
int print_string(const char *str)
{
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
		count += _putchar(*str++);

	return (count);
}
