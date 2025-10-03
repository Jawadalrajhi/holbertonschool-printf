#include "main.h"

/**
 * handle_percent - Process a '%' sequence at format[*pi].
 * @fmt: format string.
 * @pi: pointer to current index (advanced past the specifier).
 * @ap: varargs list.
 * Return: number of chars printed, or -1 on error.
 */

/* handle one specifier after '%' and advance index */
static int handle_percent(const char *fmt, int *pi, va_list *ap)
{
	int printed = 0;
	print_func fn;

	if (fmt[*pi] == '\0')
		return (-1);

	if (fmt[*pi] == '%')
	{
		_putchar('%');
		(*pi)++;
		return (1);
	}

	fn = get_printer(fmt[*pi]);
	if (fn)
		printed += fn(ap);
	else
	{
		_putchar('%');
		_putchar(fmt[*pi]);
		printed += 2;
	}
	(*pi)++;
	return (printed);
}

/* minimal printf: supports %c, %s, %% */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, count = 0;
	int r;

	if (!format)
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

		i++;
		r = handle_percent(format, &i, &ap);
		if (r < 0)
		{
			va_end(ap);
			return (-1);
		}
		count += r;
	}

	va_end(ap);
	return (count);
}
