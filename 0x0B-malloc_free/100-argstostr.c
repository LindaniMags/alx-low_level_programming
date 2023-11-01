#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments
 * @ac: argument count.
 * @av: argument vector.
 *
 * Return: pointer
 */
char *argstostr(int ac, char **av)
{
	char *args;
	int a, b, count, val;

	if (ac == 0)
	{
		return (NULL);
	}
	for (a = b = 0; b < ac; b++)
	{
		if (av[b] == NULL)
			return (NULL);

		for (count = 0; av[b][count] != '\0'; count++)
			a++;
		a++;
	}

	args = malloc((a + 1) * sizeof(char));

	if (args == NULL)
	{
		free(args);
		return (NULL);
	}

	for (b = count = val = 0; val < a; count++, val++)
	{
		if (av[b][count] == '\0')
		{
			args[val] = '\n';
			b++;
			val++;
			count = 0;
		}
		if (val < a - 1)
			args[val] = av[b][count];
	}
	args[val] = '\0';

	return (args);
}
