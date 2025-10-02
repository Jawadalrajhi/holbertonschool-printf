#include "main.h"

/* minimal printf: handles %c, %s, %% */
int _printf(const char *format, ...) { va_list ap; int count = 0; size_t i;

	if (!format) return (-1);

	va_start(ap, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
			continue;
		}

		i++;                /* move to specifier */
		if (!format[i])    /* stray '%' at end */
		{
			va_end(ap);
			return (-1);
		}
		if (format[i] == '%') /* print literal '%' */
		{
			_putchar('%');
			count++;
			continue;
		}

		{
			print_func fn = get_printer(format[i]); /* pick printer */
			if (fn)
				count += fn(&ap);                  /* call printer */
			else
			{
				/* unknown spec: print it as-is */
				_putchar('%');
				_putchar(format[i]);
				count += 2;
			}
		}
	}

	va_end(ap);
	return (count);
}
