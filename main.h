#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* _printf - prints formatted output to stdout */
int _printf(const char *format, ...);

/* _putchar - writes a single character to stdout */
int _putchar(char c);

/* print_char - prints a char from va_list */
int print_char(va_list args);

/* print_string - prints a string from va_list */
int print_string(va_list args);

/* print_int - prints an integer from va_list */
int print_int(va_list args);

/* Add more helper functions if needed */

#endif /* MAIN_H */
