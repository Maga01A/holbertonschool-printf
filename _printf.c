#include "main.h"

/**
 * handle_format - Handles format specifiers
 * @format: Format specifier
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int handle_format(const char format, va_list args)
{
	int count = 0;

	switch (format)
	{
	case 'c':
		count += _putchar(va_arg(args, int));
		break;
	case 's':
		count += print_string(va_arg(args, char *));
		break;
	case '%':
		count += _putchar('%');
		break;
	case 'd':
	case 'i':
		count += print_number(va_arg(args, int));
		break;
	default:
		count += _putchar('%');
		count += _putchar(format);
		break;
	}
	return (count);
}

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
			{
				va_end(args);
				return (-1);
			}
			count += handle_format(*format, args);
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}
	va_end(args);

	return (count);
}

