#include "main.h"
#include <stdio.h>  /* for sprintf in print_S */

/* ======== Core Printers ======== */

/* Print a single character (%c) */
int print_char(va_list *ap)
{
    int ch = va_arg(*ap, int);
    _putchar((char)ch);
    return (1);
}

/* Print a string (%s) */
int print_string(va_list *ap)
{
    char *s = va_arg(*ap, char *);
    int i = 0;

    if (!s)
        s = "(null)";

    while (s[i])
    {
        _putchar(s[i]);
        i++;
    }
    return (i);
}

/* Print a literal percent sign (%%) */
int print_percent(va_list *ap)
{
    (void)ap;
    _putchar('%');
    return (1);
}

/* Print signed integer (%d, %i) */
int print_int(va_list *ap)
{
    long n = va_arg(*ap, int);
    int count = 0;
    long div = 1;

    if (n < 0)
    {
        _putchar('-');
        count++;
        n = -n;
    }

    while (n / div >= 10)
        div *= 10;

    while (div > 0)
    {
        _putchar((n / div) % 10 + '0');
        count++;
        div /= 10;
    }

    return (count);
}

/* ======== Advanced Printers ======== */

/* Print non-printable characters as hex (%S) */
int print_S(va_list *ap)
{
    char *s = va_arg(*ap, char *);
    int i = 0, count = 0;
    char hex[3];

    if (!s)
        s = "(null)";

    while (s[i])
    {
        if ((s[i] > 0 && s[i] < 32) || (s[i] >= 127))
        {
            sprintf(hex, "%02X", (unsigned char)s[i]);
            _putchar('\\');
            _putchar('x');
            _putchar(hex[0]);
            _putchar(hex[1]);
            count += 4;
        }
        else
        {
            _putchar(s[i]);
            count++;
        }
        i++;
    }

    return count;
}

/* Print integer in binary (%b) */
int print_binary(va_list *ap)
{
    unsigned int n = va_arg(*ap, unsigned int);
    int count = 0;
    unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
    int started = 0;

    while (mask)
    {
        if (n & mask)
        {
            _putchar('1');
            started = 1;
        }
        else if (started)
        {
            _putchar('0');
        }
        mask >>= 1;
        if (started)
            count++;
    }

    if (!started)
    {
        _putchar('0');
        count = 1;
    }

    return count;
}

/* Print reversed string (%r) */
int print_reverse(va_list *ap)
{
    char *s = va_arg(*ap, char *);
    int len = 0, i;

    if (!s)
        s = "(null)";

    while (s[len])
        len++;

    for (i = len - 1; i >= 0; i--)
        _putchar(s[i]);

    return len;
}

/* Print ROT13 encoded string (%R) */
int print_rot13(va_list *ap)
{
    char *s = va_arg(*ap, char *);
    int i = 0;
    char c;

    if (!s)
        s = "(null)";

    while (s[i])
    {
        c = s[i];
        if ((c >= 'A' && c <= 'Z'))
            c = ((c - 'A' + 13) % 26) + 'A';
        else if ((c >= 'a' && c <= 'z'))
            c = ((c - 'a' + 13) % 26) + 'a';

        _putchar(c);
        i++;
    }

    return i;
}

/* Print unsigned integer in decimal (%u) */
int print_unsigned(va_list *ap)
{
    unsigned int n = va_arg(*ap, unsigned int);
    int count = 0;
    unsigned int div = 1;

    while (n / div >= 10)
        div *= 10;

    while (div > 0)
    {
        _putchar((n / div) % 10 + '0');
        count++;
        div /= 10;
    }

    return count;
}

/* Print integer in octal (%o) */
int print_octal(va_list *ap)
{
    unsigned int n = va_arg(*ap, unsigned int);
    int i, count = 0;
    char buffer[32];
    int idx = 0;

    if (n == 0)
    {
        _putchar('0');
        return 1;
    }

    while (n)
    {
        buffer[idx++] = '0' + (n % 8);
        n /= 8;
    }

    for (i = idx - 1; i >= 0; i--)
    {
        _putchar(buffer[i]);
        count++;
    }

    return count;
}

/* Print integer in hexadecimal lower case (%x) */
int print_hex_lower(va_list *ap)
{
    unsigned int n = va_arg(*ap, unsigned int);
    int i, count = 0;
    char buffer[32];
    int idx = 0;
    char hex[] = "0123456789abcdef";

    if (n == 0)
    {
        _putchar('0');
        return 1;
    }

    while (n)
    {
        buffer[idx++] = hex[n % 16];
        n /= 16;
    }

    for (i = idx - 1; i >= 0; i--)
    {
        _putchar(buffer[i]);
        count++;
    }

    return count;
}

/* Print integer in hexadecimal upper case (%X) */
int print_hex_upper(va_list *ap)
{
    unsigned int n = va_arg(*ap, unsigned int);
    int i, count = 0;
    char buffer[32];
    int idx = 0;
    char hex[] = "0123456789ABCDEF";

    if (n == 0)
    {
        _putchar('0');
        return 1;
    }

    while (n)
    {
        buffer[idx++] = hex[n % 16];
        n /= 16;
    }

    for (i = idx - 1; i >= 0; i--)
    {
        _putchar(buffer[i]);
        count++;
    }

    return count;
}

/* Print pointer address (%p) */
int print_pointer(va_list *ap)
{
    void *ptr = va_arg(*ap, void *);
    unsigned long n = (unsigned long)ptr;
    int i, count = 0;
    char buffer[32];
    int idx = 0;
    char hex[] = "0123456789abcdef";

    if (ptr == NULL)
    {
        _putchar('(');
        _putchar('n');
        _putchar('i');
        _putchar('l');
        _putchar('l');
        return 5;
    }

    while (n)
    {
        buffer[idx++] = hex[n % 16];
        n /= 16;
    }

    _putchar('0');
    _putchar('x');
    count = 2;

    for (i = idx - 1; i >= 0; i--)
    {
        _putchar(buffer[i]);
        count++;
    }

    return count;
}

/* ======== get_printer Dispatcher ======== */

print_func get_printer(char c)
{
    if (c == 'c')
        return print_char;
    if (c == 's')
        return print_string;
    if (c == '%')
        return print_percent;
    if (c == 'd' || c == 'i')
        return print_int;
    if (c == 'S')
        return print_S;
    if (c == 'b')
        return print_binary;
    if (c == 'r')
        return print_reverse;
    if (c == 'R')
        return print_rot13;
    if (c == 'u')
        return print_unsigned;
    if (c == 'o')
        return print_octal;
    if (c == 'x')
        return print_hex_lower;
    if (c == 'X')
        return print_hex_upper;
    if (c == 'p')
        return print_pointer;

    return 0;
}

