#include <stdio.h>
#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @str: string to be converted
 *
 * Return: integer
 */
int _atoi(char *str)
{
	int i, a, b, l, c, val;

	i = 0;
	a = 0;
	b = 0;
	l = 0;
	c = 0;
	val = 0;

	while (str[l] != '\0')
		l++;

	while (i < l && c == 0)
	{
		if (str[i] == '-')
			++a;

		if (str[i] >= '0' && str[i] <= '9')
		{
			val = str[i] - '0';
			if (a % 2)
				val = -val;
			b = b * 10 + val;
			c = 1;
			if (str[i + 1] < '0' || str[i + 1] > '9')
				break;
			c = 0;
		}
		i++;
	}

	if (c == 0)
		return (0);

	return (b);
}

/**
 * main - adds two  numbers
 * @argc: argument count
 * @argv: arguent vector
 *
 * Return: 0 
 */
int main(int argc, char *argv[])
{
	int sum, num, i, j, count;

	sum = 0;

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
			{
				puts("Error");
				return (1);
			}
		}
	}

	for (count = 1; count < argc; count++)
	{
		num = _atoi(argv[count]);
		if (num >= 0)
		{
			sum += num;
		}
	}

	printf("%d\n", sum);
	return (0);
}
