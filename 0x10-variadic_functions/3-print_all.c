#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>


/**
 * print_all - prints anything
 * @format: anything
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	char *str, *sprtr = "";

	va_list anythng;

	va_start(anythng, format);

	if (format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					printf("%s%c", sprtr, va_arg(anythng, int));
					break;
				case 'i':
					printf("%s%d", sprtr, va_arg(anythng, int));
					break;
				case 'f':
					printf("%s%f", sprtr, va_arg(anythng, double));
					break;
				case 's':
					str = va_arg(anythng, char *);
					if (!str)
						str = "(nil)";
					printf("%s%s", sprtr, str);
					break;
				default:
					i++;
					continue;
			}
			sprtr = ", ";
			i++;
		}
	}

	printf("\n");
	va_end(anythng);
}
