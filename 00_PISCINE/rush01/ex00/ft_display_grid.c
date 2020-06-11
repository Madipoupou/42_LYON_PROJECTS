/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_build_grid.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/14 16:04:02 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/15 15:42:11 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_sudoku.h"

void	ft_display_grid(int **grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			ft_putchar(grid[i][j] + '0');
			if (j < SIZE - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}
