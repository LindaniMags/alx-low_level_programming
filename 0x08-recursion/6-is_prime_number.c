#include "main.h"

int prime_num(int num, int i);

/**
 * is_prime_number - returns 1 if the input integer is a prime number
 * @n: number to evaluate
 *
 * Return: 1 if n is a prime number, else 0
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (prime_num(n, n - 1));
}

/**
 * prime_num - calculates if a number is prime recursively
 * @num: number to evaluate
 * @i: counter
 *
 * Return: 1 if n is prime, else 0
 */
int prime_num(int num, int i)
{
	if (i == 1)
		return (1);
	if (num % i == 0 && i > 0)
		return (0);
	return (prime_num(num, i - 1));
}
