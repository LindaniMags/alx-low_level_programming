#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings.
 * @s1: string 1.
 * @s2: string 2.
 *
 * Return: pointer to new memory block
 */
char *str_concat(char *s1, char *s2)
{
	char *strptr;
	unsigned int i, j, count, test;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		;

	for (j = 0; s2[j] != '\0'; j++)
		;

	strptr = malloc(sizeof(char) * (i + j + 1));

	if (strptr == NULL)
	{
		free(strptr);
		return (NULL);
	}

	for (count = 0; count < i; count++)
		strptr[count] = s1[count];

	test = j;
	for (j = 0; j <= test; count++, j++)
		strptr[count] = s2[j];

	return (strptr);
}
