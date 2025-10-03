#include "main.h"

/*
 * Minimal printf clone that supports: %c, %s, %%
 * Fix applied: declare 'fn' at top (C90) and reuse it (no redeclare in loop).
 */
int _printf(const char *format, ...)
{
	va_list ap;         /* variadic args state */
	int i = 0;          /* index in format string */
	int count = 0;      /* total printed chars */
	print_func fn = NULL; /* declare here (before code) to satisfy C90 */

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (format[i] != '\0')
	{
		/* normal character -> print and move on */
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
			i++;
			continue;
		}

		/* we saw '%': move to specifier */
		i++;

		/* stray '%' at end -> error as real printf would be undefined; we return -1 */
		if (format[i] == '\0')
		{
			va_end(ap);
			return (-1);
		}

		/* "%%" -> print one '%' */
		if (format[i] == '%')
		{
			_putchar('%');
			count++;
			i++;
			continue;
		}

		/* pick printer for this specifier (no re-declaration of fn here) */
		fn = get_printer(format[i]);

		if (fn != NULL)
		{
			/* call the printer; it consumes from va_list and returns printed count */
			count += fn(&ap);
		}
		else
		{
			/* unknown specifier -> print it raw as %X */
			_putchar('%');
			_putchar(format[i]);
			count += 2;
		}

		i++; /* move past specifier */
	}

	va_end(ap);
	return (count);
}
