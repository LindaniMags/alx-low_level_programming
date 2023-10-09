#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * letter - checks if a string contains a letter or special char
 * @s: string to be checked
 *
 * Return: 0 if a letter or special char is found, 1 otherwise
 */
int letter(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * errors - handles errors for main
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - multiplies two integers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int l1, l2, l, i, count, num1, num2, *res, a = 0;

	s1 = argv[1], s2 = argv[2];
	if (argc != 3 || !letter(s1) || !letter(s2))
		errors();
	l1 = _strlen(s1);
	l2 = _strlen(s2);
	l = l1 + l2 + 1;
	res = malloc(sizeof(int) * l);
	if (!res)
		return (1);
	for (i = 0; i <= l1 + l2; i++)
		res[i] = 0;
	for (l1 = l1 - 1; l1 >= 0; l1--)
	{
		num1 = s1[l1] - '0';
		count = 0;
		for (l2 = _strlen(s2) - 1; l2 >= 0; l2--)
		{
			num2 = s2[l2] - '0';
			count += res[l1 + l2 + 1] + (num1 * num2);
			res[l1 + l2 + 1] = count % 10;
			count /= 10;
		}
		if (count > 0)
			res[l1 + l2 + 1] += count;
	}
	for (i = 0; i < l - 1; i++)
	{
		if (res[i])
			a = 1;
		if (a)
			_putchar(res[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(res);
	return (0);
}
