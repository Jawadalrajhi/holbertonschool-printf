#include "main.h"
#include <unistd.h>

/* print a single char */
int print_char(va_list *ap)
{
	int c = va_arg(*ap, int);

	_putchar((char)c);
	return (1);
}

/* print a C-string (handles NULL) */
int print_string(va_list *ap)
{
	char *s = va_arg(*ap, char *);
	int n = 0;

	if (!s)
		s = "(null)";

	while (s[n])
	{
		_putchar(s[n]);
		n++;
	}
	return (n);
}

/* print a literal '%' */
int print_percent(va_list *ap)
{
	(void)ap;
	_putchar('%');
	return (1);
}

/* static dispatch table */
static const spec_t table[] = {
	{ 'c', print_char },
	{ 's', print_string },
	{ '%', print_percent },
	{ '\0', NULL }
};

/* find printer by specifier */
print_func get_printer(char c)
{
	size_t i = 0;

	while (table[i].spec != '\0')
	{
		if (table[i].spec == c)
			return (table[i].fn);
		i++;
	}
	return (NULL);
}
