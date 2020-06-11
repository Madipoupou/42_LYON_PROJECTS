/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_grid.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/14 16:50:25 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/15 16:29:29 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_sudoku.h"

t_bool	ft_check_row(int *row)
{
	int i;
	int j;

	i = 0;
	while (i < SIZE - 1)
	{
		if (row[i] != 0)
		{
			j = i + 1;
			while (j < SIZE)
			{
				if (row[j] != 0 && row[i] == row[j])
					return (FALSE);
				j++;
			}
		}
		i++;
	}
	return (TRUE);
}

t_bool	ft_check_col(int **grid, int col)
{
	int i;
	int j;

	i = 0;
	while (i < SIZE - 1)
	{
		j = i + 1;
		if (grid[i][col] != 0)
		{
			while (j < SIZE)
			{
				if (grid[j][col] != 0 && (grid[i][col] == grid[j][col]))
					return (FALSE);
				j++;
			}
		}
		i++;
	}
	return (TRUE);
}

t_bool	ft_check_grid(int **grid)
{
	int i;
	int test;

	i = 0;
	test = TRUE;
	while (i < SIZE)
	{
		test = test && ft_check_row(grid[i]);
		test = test && ft_check_col(grid, i);
		test = test && ft_check_block(grid, i);
		if (!test)
			return (FALSE);
		i++;
	}
	return (test);
}
