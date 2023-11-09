#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: array
 * @size: size of array
 * @cmp: pointer function used to compare
 *
 * Return: index of the first element if cmp is not 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
				return (i);
		}
	}

	return (-1);
}
