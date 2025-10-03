
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
 * get_printer - map a specifier to its print function
 * @c: conversion specifier (e.g. 'c', 's', '%')
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
	return (0);
}
