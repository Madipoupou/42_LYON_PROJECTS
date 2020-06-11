/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sudoku.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 23:44:43 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/15 21:03:32 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_sudoku.h"

int	main(int argc, char **argv)
{
	int **grid;
	int **grid2;

	if (!(argc == 10 && ft_check_linelen(argv)))
	{
		ft_putstr("Error\n");
		return (0);
	}
	grid = ft_build_grid(argv);
	if (!grid || !(grid2 = ft_build_grid(argv)))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!ft_check_grid(grid))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!(ft_solve(grid, NULL) && ft_solve(grid2, grid)))
		ft_display_grid(grid);
	else
		ft_putstr("Error\n");
	ft_free_memory(grid, grid2);
	return (0);
}
