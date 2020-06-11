/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_block.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/14 23:04:01 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/15 16:29:04 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_sudoku.h"

void	ft_get_block_pos(int block_num, int *i, int *j)
{
	if (block_num < 3)
		*i = 0;
	else if (block_num < 6)
		*i = 3;
	else
		*i = 6;
	if (block_num % 3 == 0)
		*j = 0;
	else if (block_num % 3 == 1)
		*j = 3;
	else
		*j = 6;
}

t_bool	ft_test_block_elt(int **grid, int i1, int j1, int block_num)
{
	int i2;
	int j2;
	int i_start;
	int j_start;

	ft_get_block_pos(block_num, &i_start, &j_start);
	i2 = i_start;
	j2 = j_start;
	while (j2 < j_start + 3)
	{
		if ((i2 != i1 || j2 != j1) && grid[i2][j2] != 0)
		{
			if (grid[i1][j1] == grid[i2][j2])
				return (FALSE);
		}
		i2++;
		if (i2 == i_start + 3)
		{
			i2 = i_start;
			j2++;
		}
	}
	return (TRUE);
}

t_bool	ft_check_block(int **grid, int block_num)
{
	int	i_start;
	int j_start;
	int i;
	int j;
	int test;

	ft_get_block_pos(block_num, &i_start, &j_start);
	i = i_start;
	j = j_start;
	while (j < j_start + 3)
	{
		if (grid[i][j] != 0)
		{
			test = ft_test_block_elt(grid, i, j, block_num);
			if (!test)
				return (FALSE);
		}
		i++;
		if (i == i_start + 3)
		{
			j++;
			i = i_start;
		}
	}
	return (TRUE);
}
