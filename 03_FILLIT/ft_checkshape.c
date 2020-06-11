/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_checkshape.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 13:33:02 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/27 14:29:43 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_abs(int x)
{
	if (x < 0)
		return (-1 * x);
	return (x);
}

static int	ft_countfriends(t_shape *s, size_t i)
{
	int		cpt;
	size_t	j;

	j = 0;
	cpt = 0;
	while (j < SHAPE_SIZE)
	{
		if (j != i)
		{
			if (
					(ft_abs(s->coord[j][0] - s->coord[i][0]) == 1 &&
					ft_abs(s->coord[j][1] - s->coord[i][1]) == 0) ||
					(ft_abs(s->coord[j][0] - s->coord[i][0]) == 0 &&
					ft_abs(s->coord[j][1] - s->coord[i][1]) == 1))
				cpt++;
		}
		j++;
	}
	return (cpt);
}

int			ft_checkshape(t_list *cur)
{
	int		friends;
	size_t	i;
	t_shape	*s;

	s = (t_shape *)(cur->content);
	friends = 0;
	i = 0;
	while (i < SHAPE_SIZE)
	{
		friends += ft_countfriends(s, i);
		i++;
	}
	if (friends < 6)
		return (0);
	return (1);
}
