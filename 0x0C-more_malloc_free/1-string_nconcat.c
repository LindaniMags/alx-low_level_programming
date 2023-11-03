#include <stdlib.h>
#include "main.h"

/**
 * *string_nconcat - concatenates two strings
 * @s1: append to
 * @s2: concatenate from
 * @n: bytes
 *
 * Return: pointer to string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s_init;
	unsigned int i = 0, j = 0, l1 = 0, l2 = 0;

	while (s1 && s1[l1])
		l1++;
	while (s2 && s2[l2])
		l2++;

	if (n < l2)
		s_init = malloc(sizeof(char) * (l1 + n + 1));
	else
		s_init = malloc(sizeof(char) * (l1 + l2 + 1));

	if (!s_init)
		return (NULL);

	while (i < l1)
	{
		s_init[i] = s1[i];
		i++;
	}

	while (n < l2 && i < (l1 + n))
		s_init[i++] = s2[j++];

	while (n >= l2 && i < (l1 + l2))
		s_init[i++] = s2[j++];

	s_init[i] = '\0';

	return (s_init);
}
