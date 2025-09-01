#include "main.h"

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

    count += _putchar('0');
    count += _putchar('x');
    count += print_hex(addr, 0);

    return (count);
}

