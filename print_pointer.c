#include "main.h"
#include <unistd.h>

/**
 * print_hex_ulong - prints an unsigned long in lowercase hexadecimal
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_hex_ulong(unsigned long n)
{
	int count = 0;
	char *hex = "0123456789abcdef";

	if (n / 16)
		count += print_hex_ulong(n / 16);

	count += write(1, &hex[n % 16], 1);

	return (count);
}

/**
 * print_pointer - prints a pointer address
 * @p: pointer to print
 *
 * Return: number of characters printed
 */
int print_pointer(void *p)
{
	unsigned long addr = (unsigned long)p;
	int count = 0;

	if (!p)
		return (write(1, "(nil)", 5));

	count += write(1, "0x", 2);
	count += print_hex_ulong(addr);

	return (count);
}

