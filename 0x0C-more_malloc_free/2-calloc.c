#include <stdlib.h>
#include "main.h"

/**
 * *_memset - fills a block of memory with a particular value
 * @pt: memory area
 * @x: char to copy
 * @n: number of times to copy x
 *
 * Return: pointer pt
 */
char *_memset(char *pt, char x, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		pt[i] = x;
	}

	return (pt);
}

/**
 * *_calloc - allocates memory for an array
 * @nmemb: number of elements
 * @size: size of element
 *
 * Return: pointer
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(size * nmemb);

	if (p == NULL)
		return (NULL);

	_memset(p, 0, nmemb * size);

	return (p);
}
