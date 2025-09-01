#include "main.h"

/* --------------------------
   Yeni yardımcı prototipler
   -------------------------- */
int print_binary(unsigned int n);   /* %b */
int print_S(char *s);               /* %S */
int print_pointer(void *p);         /* %p */

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i]) /* % sonrası string sonu kontrolü */
                return (-1);

            switch (format[i])
            {
                case 'c': /* karakter */
                    count += _putchar(va_arg(args, int));
                    break;
                case 's': /* string */
                    count += print_string(va_arg(args, char *));
                    break;
                case 'd':
                case 'i': /* signed integer */
                    count += print_number(va_arg(args, int));
                    break;
                case 'u': /* unsigned integer */
                    count += print_unsigned(va_arg(args, unsigned int));
                    break;
                case 'o': /* octal */
                    count += print_octal(va_arg(args, unsigned int));
                    break;
                case 'x': /* hex lowercase */
                    count += print_hex(va_arg(args, unsigned int), 0);
                    break;
                case 'X': /* hex uppercase */
                    count += print_hex(va_arg(args, unsigned int), 1);
                    break;
                case 'b': /* binary ✅ yeni eklendi */
                    count += print_binary(va_arg(args, unsigned int));
                    break;
                case 'S': /* special string ✅ yeni eklendi */
                    count += print_S(va_arg(args, char *));
                    break;
                case 'p': /* pointer ✅ yeni eklendi */
                    count += print_pointer(va_arg(args, void *));
                    break;
                case '%': /* %% */
                    count += _putchar('%');
                    break;
                default: /* bilinmeyen format */
                    count += _putchar('%');
                    count += _putchar(format[i]);
                    break;
            }
        }
        else
        {
            count += _putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return (count);
}

/* --------------------------
   Binary yazdırma (%b)
   -------------------------- */
int print_binary(unsigned int n)
{
    int count = 0, flag = 0;
    unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);

    if (n == 0)
        return (_putchar('0'));

    while (mask)
    {
        if (n & mask)
        {
            count += _putchar('1');
            flag = 1;
        }
        else if (flag)
            count += _putchar('0');
        mask >>= 1;
    }
    return (count);
}

/* --------------------------
   Non-printable karakterleri \xHH formatında (%S)
   -------------------------- */
int print_S(char *s)
{
    int i, count = 0;
    char *hex = "0123456789ABCDEF";

    if (!s)
        return (print_string("(null)"));

    for (i = 0; s[i]; i++)
    {
        if (s[i] < 32 || s[i] >= 127)
        {
            count += _putchar('\\');
            count += _putchar('x');
            count += _putchar(hex[(s[i] >> 4) & 0xF]);
            count += _putchar(hex[s[i] & 0xF]);
        }
        else
            count += _putchar(s[i]);
    }
    return (count);
}

/* --------------------------
   Pointer yazdırma (%p)
   -------------------------- */
int print_pointer(void *p)
{
    unsigned long int n;
    int count = 0;
    char buffer[20];
    char *hex = "0123456789abcdef";
    int i = 0;

    if (!p)
        return (print_string("(nil)"));

    n = (unsigned long int)p;
    count += print_string("0x");

    if (n == 0)
        return (count + _putchar('0'));

    while (n > 0)
    {
        buffer[i++] = hex[n % 16];
        n /= 16;
    }
    while (i--)
        count += _putchar(buffer[i]);

    return (count);
}

