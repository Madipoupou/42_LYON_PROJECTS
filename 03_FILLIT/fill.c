/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/27 16:29:19 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/27 18:19:26 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clear(t_shape *s, char **grid, int *tab)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		grid[tab[0] + s->coord[i][0]][tab[1] + s->coord[i][1]] = '.';
		i++;
	}
	return ;
}

int		ft_findindex(char **grid, int *tab)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = tab[0];
	j = tab[1] + 1;
	len = ft_strlen(grid[i]);
	while (grid[i] != NULL)
	{
		while (j < len)
		{
			if (grid[i][j] == '.')
			{
				tab[0] = i;
				tab[1] = j;
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		ft_putshape(char **grid, t_shape *s, int *tab, int size)
{
	int	i;
	int	j;

	i = tab[0];
	j = tab[1];
	if ((i + s->coord[0][0] >= 0) && (j + s->coord[0][1] >= 0) &&
		(i + s->coord[1][0] >= 0) && (j + s->coord[1][1] >= 0) &&
		(i + s->coord[2][0] >= 0) && (j + s->coord[2][1] >= 0) &&
		(i + s->coord[3][0] >= 0) && (j + s->coord[3][1] >= 0) &&
		(i + s->coord[0][0] < size) && (j + s->coord[0][1] < size) &&
		(i + s->coord[1][0] < size) && (j + s->coord[1][1] < size) &&
		(i + s->coord[2][0] < size) && (j + s->coord[2][1] < size) &&
		(i + s->coord[3][0] < size) && (j + s->coord[3][1] < size))
		if ((grid[i + s->coord[0][0]][j + s->coord[0][1]] == '.') &&
				(grid[i + s->coord[1][0]][j + s->coord[1][1]] == '.') &&
				(grid[i + s->coord[2][0]][j + s->coord[2][1]] == '.') &&
				(grid[i + s->coord[3][0]][j + s->coord[3][1]] == '.'))
		{
			grid[i + s->coord[0][0]][j + s->coord[0][1]] = s->letter;
			grid[i + s->coord[1][0]][j + s->coord[1][1]] = s->letter;
			grid[i + s->coord[2][0]][j + s->coord[2][1]] = s->letter;
			grid[i + s->coord[3][0]][j + s->coord[3][1]] = s->letter;
			return (1);
		}
	return (0);
}
