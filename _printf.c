#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: the format string containing characters and specifiers
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
va_list ap;
int count = 0;
size_t i;
if (!format)
return (-1);
va_start(ap, format);
for (i = 0; format[i]; i++)
{
if (format[i] != '%')
{
_putchar(format[i]);
count++;
continue;
}
i++;
if (!format[i])
{
va_end(ap);
return (-1);
}
if (format[i] == '%')
{
_putchar('%');
count++;
continue;
}
{
print_func fn = get_printer(format[i]);
if (fn)
count += fn(&ap);
else
{
_putchar('%');
_putchar(format[i]);
count += 2;
}
}
va_end(ap);
return (count);
}
