/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_solve.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/15 03:28:27 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/15 20:23:28 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_sudoku.h"

t_bool	ft_compare(int **grid, int **grid2)
{
	int i;
	int j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (grid[i][j] != grid2[i][j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_bool	ft_find_first_empty(int **grid, int *i, int *j)
{
	int i1;
	int j1;

	i1 = 0;
	while (i1 < SIZE)
	{
		j1 = 0;
		while (j1 < SIZE)
		{
			if (grid[i1][j1] == 0)
			{
				*i = i1;
				*j = j1;
				return (TRUE);
			}
			j1++;
		}
		i1++;
	}
	return (FALSE);
}

t_bool	ft_solve(int **grid, int **grid2)
{
	int	i;
	int j;
	int sol;
	int k;

	if (!ft_check_grid(grid))
		return (FALSE);
	else if (!ft_find_first_empty(grid, &i, &j) && ft_check_grid(grid))
	{
		if (grid2)
			return (!ft_compare(grid, grid2));
		return (TRUE);
	}
	k = 1;
	while (k <= SIZE)
	{
		grid[i][j] = k;
		sol = ft_solve(grid, grid2);
		if (sol)
			return (TRUE);
		k++;
	}
	grid[i][j] = 0;
	return (FALSE);
}
