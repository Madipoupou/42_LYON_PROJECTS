/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 13:07:39 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 15:00:44 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		ft_abs(int a)
{
	if (a < 0)
		return (-1 * a);
	return (a);
}

void	ft_lstintdel(void *content, size_t size)
{
	size_t	i;

	i = size;
	if (i == size)
		free(content);
}

void	ft_strtabdel(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_strdel(tab + i);
		i++;
	}
}
