#include "main.h"
#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory.
 * @str: string.
 *
 * Return: pointer to memory block
 */
char *_strdup(char *str)
{
	char *strptr;
	unsigned int i, count;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;

	strptr = (char *)malloc(sizeof(char) * (i + 1));

	if (strptr == NULL)
		return (NULL);

	for (count = 0; count <= i; count++)
		strptr[count] = str[count];

	return (strptr);
}
