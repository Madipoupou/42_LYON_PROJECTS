/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_memory.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/15 21:04:03 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/15 21:06:39 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_sudoku.h"

void	ft_free_memory(int **grid, int **grid2)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		free(grid[i]);
		free(grid2[i]);
		i++;
	}
	free(grid);
	free(grid2);
}
