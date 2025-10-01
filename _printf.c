#include "main.h"
#include <stdarg.h>

/**
 * get_printer - returns the function that prints a given specifier
 * @sp: conversion specifier
 *
 * Return: pointer to a printer function, or NULL if not found
 */
static int (*get_printer(char sp))(va_list)
{
	if (sp == 'c')
		return (print_char);
	if (sp == 's')
		return (print_string);
	if (sp == '%')
		return (print_int);
	return (NULL);
}

/**
 * _printf - produces output according to a format
 * @format: format string containing zero or more directives
 *
 * Return: number of characters printed (excluding the null byte),
 * or -1 on error (e.g. NULL format or trailing '%')
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0, i = 0;
	int (*printer)(va_list);

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
			i++;
			continue;
		}
		/* we saw a '%' */
		i++;
		if (format[i] == '\0')
		{
			va_end(ap);
			return (-1);
		}

		printer = get_printer(format[i]);
		if (printer != NULL)
		{
			count += printer(ap);
		}
		else
		{
			_putchar('%');
			_putchar(format[i]);
			count += 2;
		}
		i++;
	}

	va_end(ap);
	return (count);
}
