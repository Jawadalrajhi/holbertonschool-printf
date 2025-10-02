#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

/* _printf - prints formatted output to stdout */
int _printf(const char *format, ...);

/* _putchar - writes a single character to stdout */
int _putchar(char c);

/* function pointer type and spec table entry */
typedef int (*print_func)(va_list *ap);
typedef struct spec {
    char spec;
    print_func fn;
}spec_t;

/* print_char - prints a char from va_list */
int print_char(va_list *ap);

/* print_string - prints a string from va_list */
int print_string(va_list *ap);

/* print_percent - prints an integer from va_list */
int print_percent(va_list *ap);

/* printers */
print_func get_printer(char c);

/* Add more helper functions if needed */

#endif /* MAIN_H */
