#include "main.h"

/**
 * handle_percent - process a '%' sequence inside format
 * @fmt: full format string
 * @i: pointer to current index (points to char after '%')
 * @ap: pointer to active va_list
 *
 * Return: characters printed for this sequence, or -1 on error
 */
static int handle_percent(const char *fmt, int *i, va_list *ap)
{
	print_func fn;

	/* end of string right after '%' -> error */
	if (!fmt[*i])
		return (-1);

	/* '%%' prints a single '%' */
	if (fmt[*i] == '%')
	{
		_putchar('%');
		return (1);
	}

	/* try to find a printer for %c or %s (or %) */
	fn = get_printer(fmt[*i]);
	if (fn)
		return (fn(ap));

	/* unknown specifier: print '%' then the specifier */
	_putchar('%');
	_putchar(fmt[*i]);
	return (2);
}

/**
 * _printf - minimal printf supporting %c, %s and %%
 * @format: format string to print
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, count;
	int printed; /* temp for each conversion */

	if (!format)
		return (-1);

	va_start(ap, format);
	i = 0;
	count = 0;

	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
			i++;
			continue;
		}

		/* we saw '%', move to the specifier char */
		i++;

		printed = handle_percent(format, &i, &ap);
		if (printed == -1)
		{
			va_end(ap);
			return (-1);
		}

		count += printed;
		i++; /* move past the specifier we just handled */
	}

	va_end(ap);
	return (count);
}
