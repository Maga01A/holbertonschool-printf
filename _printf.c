#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break;
			count += handle_format(*format, args); /* Düzeltilen yer: format işleme fonksiyonu */
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

/**
 * handle_format - Handles a single format specifier
 * @spec: Format specifier character
 * @args: va_list of arguments
 *
 * Return: Number of characters printed for this specifier
 */
int handle_format(char spec, va_list args)
{
	int count = 0;

	switch (spec)
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
		case 'u':
			count += print_unsigned(va_arg(args, unsigned int));
			break;
		case 'o':
			count += print_octal(va_arg(args, unsigned int));
			break;
		case 'x':
			count += print_hex(va_arg(args, unsigned int), 0);
			break;
		case 'X':
			count += print_hex(va_arg(args, unsigned int), 1);
			break;
		case 'p':
			count += print_pointer(va_arg(args, void *));
			break;
		default:
			count += _putchar('%');
			count += _putchar(spec);
			break;
	}
	return (count);
}

