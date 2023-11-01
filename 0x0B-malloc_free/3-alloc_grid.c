#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: width of the array.
 * @height: height of the array.
 *
 * Return: pointer of an array of integers
 */
int **alloc_grid(int width, int height)
{
	int **arr_2d;
	int i, j;

	if (width < 1 || height < 1)
		return (NULL);

	arr_2d = malloc(height * sizeof(int *));
	if (arr_2d == NULL)
	{
		free(arr_2d);
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		arr_2d[i] = malloc(width * sizeof(int));
		if (arr_2d[i] == NULL)
		{
			for (i--; i >= 0; i--)
				free(arr_2d[i]);
			free(arr_2d);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			arr_2d[i][j] = 0;

	return (arr_2d);
}
