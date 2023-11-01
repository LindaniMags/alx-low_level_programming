#include "main.h"
#include <stdlib.h>

/**
 * free_grid - free previous 2D grid
 * @grid: 2D array
 * @height: height
 *
 * Return: no return
 */
void free_grid(int **grid, int height)
{
	if (grid != NULL && height != 0)
	{
		for (; height >= 0; height--)
			free(grid[height]);
		free(grid);
	}
}
