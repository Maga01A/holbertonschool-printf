#include "main.h"/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
	char buffer[12];
	int i = 0, j, count = 0;
	unsigned int num;	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
		num = n;	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}	for (j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		count++;
	}	return (count);
}/**
 * _printf - produces output according to a format
 * @format: format string containing directives
 *
 * Return: number of characters printed (excluding null byte),
 *         or -1 if format is NULL
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char c, *str;	if (format == NULL)
		return (-1);	va_start(args, format);	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = (char)va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					write(1, str, 1);
					str++;
					count++;
				}
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				count += print_number(va_arg(args, int));
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}	va_end(args);
	return (count);
}
