#include "main.h"

/**
 * print_hex - prints an unsigned int in hexadecimal
 * @n: number to print
 * @uppercase: 1 for uppercase, 0 for lowercase
 *
 * Return: number of characters printed
 */
int print_hex(unsigned int n, int uppercase)
{
    int count = 0;
    char *hex = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n / 16)
        count += print_hex(n / 16, uppercase);

    count += _putchar(hex[n % 16]);

    return (count);
}

