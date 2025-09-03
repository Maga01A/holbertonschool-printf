#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * _printf - this is mini version of ptintf(3) function
 * @format: a character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i, k = 0;
	va_list ptr;

	va_start(ptr, format);
	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == 'c')
			k = (unsigned int)_print_c(&k, va_arg(ptr, int)), i++;
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			k = (unsigned int)_print_s(&k, va_arg(ptr, char *));
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
			write(1, "%", 1), i++, k++;
		else if (format[i] == '%' && format[i + 1] == '\0')
			continue;
		else
			write(1, &format[i], 1), k++;
	}
	va_end(ptr);
	if (k == 0)
		exit(1);
	return (k);
}
