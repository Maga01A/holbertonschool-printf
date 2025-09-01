#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: Character to print
 *
 * Return: 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

