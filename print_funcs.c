#include "main.h"
#include <stdarg.h>

/**
 * print_char - prints a single character
 * @ap: variadic list
 *
 * Return: number of characters printed (1)
 */
int print_char(va_list ap)
{
	int c = va_arg(ap, int);

	_putchar(c);
	return (1);
}

/**
 * print_string - prints a C-string
 * @ap: variadic list
 *
 * Return: number of characters printed
 */
int print_string(va_list ap)
{
	char *s = va_arg(ap, char *);
	int i = 0;

	if (s == NULL)
		s = "(null)";

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}

/**
 * print_percent - prints a percent sign
 * @ap: variadic list (unused)
 *
 * Return: number of characters printed (1)
 */
int print_percent(va_list ap)
{
	(void)ap;
	_putchar('%');
	return (1);
}

