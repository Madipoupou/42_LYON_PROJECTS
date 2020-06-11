/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 14:58:34 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/27 15:11:35 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_display(char **grid)
{
	size_t	i;

	i = 0;
	while (grid[i] != NULL)
	{
		ft_putendl(grid[i]);
		i++;
	}
}

int		ft_strtabdel(char **tab)
{
	while (*tab)
	{
		ft_strdel(tab);
		tab++;
	}
	return (1);
}

void	ft_lstdelshape(void *s, size_t size)
{
	size_t	i;

	i = size;
	free(s);
}
