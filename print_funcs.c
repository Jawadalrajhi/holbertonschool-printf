#include "main.h"

/**
 * print_char - print a single character (%c)
 * @ap: pointer to va_list, contains an int promoted char
 *
 * Return: number of characters printed (1)
 */
int print_char(va_list *ap)
{
	int ch = va_arg(*ap, int);

	_putchar((char)ch);
	return (1);
}

/**
 * print_string - print a C string (%s)
 * @ap: pointer to va_list, contains (char *)
 *
 * Return: number of characters printed
 */
int print_string(va_list *ap)
{
	char *s = va_arg(*ap, char *);
	int i = 0;

	if (!s)
		s = "(null)";

	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}

/**
 * print_percent - print a literal percent sign (%%)
 * @ap: pointer to va_list (unused)
 *
 * Return: number of characters printed (1)
 */
int print_percent(va_list *ap)
{
	(void)ap;
	_putchar('%');
	return (1);
}

/**
 * print_int - print a signed integer (%d, %i)
 * @ap: pointer to va_list, contains int
 *
 * Return: number of characters printed
 */
int print_int(va_list *ap)
{
	long n = va_arg(*ap, int);
	int count = 0;
	long div = 1;

	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}

	while (n / div >= 10)
		div *= 10;

	while (div > 0)
	{
		_putchar((n / div) % 10 + '0');
		count++;
		div /= 10;
	}

	return (count);
}

/**
 * get_printer - map a specifier to its print function
 * @c: conversion specifier (e.g. 'c', 's', '%', 'd', 'i')
 *
 * Return: function pointer if known, NULL otherwise
 */
print_func get_printer(char c)
{
	if (c == 'c')
		return (print_char);
	if (c == 's')
		return (print_string);
	if (c == '%')
		return (print_percent);
	if (c == 'd' || c == 'i')
return (print_int);
return (0);
}
