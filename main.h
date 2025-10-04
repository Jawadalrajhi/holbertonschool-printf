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

/* Basic Printers (Mandatory Tasks) */
int print_char(va_list *ap);
int print_string(va_list *ap);
int print_percent(va_list *ap);
int print_int(va_list *ap);

/* Advanced Printers (Added Separately) */
int print_binary(va_list *ap);     /* %b */
int print_unsigned(va_list *ap);   /* %u */
int print_octal(va_list *ap);      /* %o */
int print_hex_lower(va_list *ap);  /* %x */
int print_hex_upper(va_list *ap);  /* %X */
int print_pointer(va_list *ap);    /* %p */
int print_S(va_list *ap);          /* %S */
int print_reverse(va_list *ap);    /* %r */
int print_rot13(va_list *ap);      /* %R */

/* Dispatcher */
print_func get_printer(char spec);

#endif /* MAIN_H */

