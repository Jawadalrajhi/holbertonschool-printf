#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * _printf - prints formatted output to stdout
 * @format: the format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...);

/**
 * _putchar - writes a single character to stdout
 * @c: the character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c);

/**
 * print_func - typedef for printer functions
 * @ap: argument list
 *
 * Return: number of characters printed
 */
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

/**
 * print_char - prints a char from va_list
 * @ap: argument list
 *
 * Return: number of characters printed
 */
int print_char(va_list *ap);

/**
 * print_string - prints a string from va_list
 * @ap: argument list
 *
 * Return: number of characters printed
 */
int print_string(va_list *ap);

/**
 * print_percent - prints a percent sign
 * @ap: argument list (unused)
 *
 * Return: number of characters printed
 */
int print_percent(va_list *ap);

/**
 * get_printer - gets the appropriate function for a specifier
 * @c: format specifier character
 *
 * Return: function pointer if found, NULL otherwise
 */
print_func get_printer(char c);

#endif /* MAIN_H */

