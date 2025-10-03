#include "main.h"

/* quick sanity test for %c, %s, %% */
int main(void)
{
	_printf("Hello %s%c %%%c\n", "World", '!', '?');
	_printf("Char: %c, String: %s, Percent: %%\n", 'A', "Test");
	return (0);
}
