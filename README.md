==========================================================================
                            Holberton School - _printf Project

Contributors: Jawad & Alanoud

Welcome to our `_printf` adventure! This project is more than just printing 
text — it’s about mastering variadic functions, function pointers, and 
custom format specifiers in C.

--------------------------------------------------------------------------
                              Project Story
--------------------------------------------------------------------------

We started by reimplementing the core printf features:

  - %c → Print a single character
  - %s → Print strings
  - %d & %i → Print signed integers
  - %% → Print a literal percent sign

Then we added advanced functionality to extend capabilities:

  - %b → Binary output of integers
  - %u → Unsigned integers
  - %o → Octal numbers
  - %x & %X → Hexadecimal numbers
  - %p → Pointer addresses
  - %S → Strings with non-printable characters printed in hex
  - %r → Reverse strings
  - %R → ROT13 encoded strings

Each advanced task has its own dedicated function, keeping the code neat, 
modular, and maintainable.

--------------------------------------------------------------------------
                             Specifier Examples
--------------------------------------------------------------------------

| Specifier | Input             | Output            |
|-----------|-----------------|-----------------|
| %c        | 'A'              | A                |
| %s        | "Hello"          | Hello            |
| %d        | 123              | 123              |
| %%        | N/A              | %                |
| %b        | 5                | 101              |
| %u        | 300              | 300              |
| %o        | 300              | 454              |
| %x        | 300              | 12c              |
| %X        | 300              | 12C              |
| %p        | &x               | 0x7ffeefbff5ac   |
| %S        | "Best\nSchool"   | Best\x0ASchool   |
| %r        | "abc"            | cba              |
| %R        | "abc"            | nop              |

--------------------------------------------------------------------------
                             Files & Structure
--------------------------------------------------------------------------

| File           | Purpose                                      |
|----------------|----------------------------------------------|
| _printf.c      | Main `_printf` function                      |
| _putchar.c     | Helper for character output                  |
| main.h         | Header file with prototypes & type definitions |
| print_funcs.c  | All printer functions: core + advanced      |
| man_3_printf   | Manual page for `_printf`                    |

--------------------------------------------------------------------------
                                Usage Example
--------------------------------------------------------------------------

#include "main.h"

int main(void)
{
    _printf("Hello %s!\n", "World");
    _printf("Binary of 98: %b\n", 98);
    _printf("Unsigned 300: %u\n", 300);
    _printf("Octal 300: %o\n", 300);
    _printf("Hex lower 300: %x\n", 300);
    _printf("Hex upper 300: %X\n", 300);
    _printf("Pointer of x: %p\n", &x);
    _printf("Non-printable string: %S\n", "Best\nSchool");
    _printf("Reverse string: %r\n", "Hello");
    _printf("ROT13 string: %R\n", "Hello");
    return 0;
}

--------------------------------------------------------------------------
                              Testing Notes
--------------------------------------------------------------------------

- Handles NULL pointers gracefully (%s, %S, %p)
- Non-printable characters in %S are printed as \xHH
- Each advanced specifier is in a dedicated function, modular code
- Ensures correct output for core and advanced tasks

==========================================================================

