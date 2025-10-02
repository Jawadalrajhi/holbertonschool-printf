#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stddef.h>

/* public API */
int _printf(const char *format, ...);

/* low-level output */
int _putchar(char c);

/* function type for a printer */
typedef int (*print_func)(va_list *ap);

/* spec table entry */
typedef struct spec {
    char spec;
    print_func fn;
} spec_t;

/* printers */
int print_char(va_list *ap);
int print_string(va_list *ap);
int print_percent(va_list *ap);

/* lookup printer by specifier */
print_func get_printer(char c);

#endif
