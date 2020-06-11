/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_solve.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/27 14:01:14 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/27 18:19:55 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static size_t	ft_minsize(size_t num_points)
{
	size_t	res;

	res = 1;
	while (res)
	{
		if (res * res >= num_points)
			break ;
		res++;
	}
	return (res);
}

static char		**ft_initgrid(size_t size)
{
	char	**grid;
	size_t	i;

	grid = ft_memalloc((size + 1) * sizeof(char *));
	if (grid == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		grid[i] = ft_strnew(size);
		if (grid[i] == NULL)
		{
			ft_strtabdel(grid);
			free(grid);
			return (NULL);
		}
		ft_memset(grid[i], '.', size);
		i++;
	}
	return (grid);
}

char			**ft_fillgrid(char **grid, t_list *lst, size_t size)
{
	t_shape	*s;
	int		ok;
	int		tab[2];

	if (lst == NULL)
		return (grid);
	s = (t_shape *)lst->content;
	tab[0] = 0;
	tab[1] = -1;
	while (1)
	{
		ok = ft_findindex(grid, tab);
		if (ok == 0)
			return (NULL);
		ok = ft_putshape(grid, s, tab, (int)size);
		if (ok)
		{
			if ((ft_fillgrid(grid, lst->next, size)) != NULL)
				return (grid);
			ft_clear(s, grid, tab);
		}
	}
}

char			**ft_solve(t_list *lst)
{
	char	**grid;
	char	**sol;
	size_t	size;

	size = ft_minsize(4 * ft_lstlen(lst));
	sol = NULL;
	while (sol == NULL)
	{
		grid = ft_initgrid(size);
		sol = ft_fillgrid(grid, lst, size);
		if (sol == NULL)
		{
			ft_strtabdel(grid);
			free(grid);
		}
		size++;
	}
	return (sol);
}
