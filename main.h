#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

/* Core functions */
int _printf(const char *format, ...);
int _putchar(char c);

/* Typedef for printer functions */
typedef int (*print_func)(va_list *ap);

/**
 * struct spec - struct for format specifiers
 * @spec: the format character (e.g. 'c', 's', 'd')
 * @fn: pointer to the corresponding printer function
 */
typedef struct spec
{
    char spec;
    print_func fn;
} spec_t;

/* Printers */
int print_char(va_list *ap);
int print_string(va_list *ap);
int print_percent(va_list *ap);
int print_int(va_list *ap); /* <-- مهم */

/* Dispatcher */
print_func get_printer(char spec);

#endif /* MAIN_H */
