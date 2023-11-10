#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - calculates the sum of its parameters
 * @n: arguments
 *
 * Return: sum
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int sum = 0;
	va_list par;

	va_start(par, n);

	for (i = 0; i < n; i++)
		sum += va_arg(par, int);

	va_end(par);

	return (sum);
}
