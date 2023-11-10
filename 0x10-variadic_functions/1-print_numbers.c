#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers -  prints numbers, followed by a new line.
 * @separator: string
 * @n: integers
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list vals;

	va_start(vals, n);

	for (i = 0; i < n; i++)
	{
		if (!separator)
			printf("%d", va_arg(vals, int));
		else if (separator && i == 0)
			printf("%d", va_arg(vals, int));
		else
			printf("%s%d", separator, va_arg(vals, int));
	}

	va_end(vals);

	printf("\n");
}
