/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   coord_tools.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 21:24:12 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 01:07:45 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_checklines(char **pts, int *ok)
{
	int	cpt;

	cpt = 0;
	while (*pts)
	{
		cpt++;
		pts++;
	}
	if (ok[1] == 0)
		ok[1] = cpt;
	else
	{
		if (cpt != ok[1])
		{
			ft_puterror("ERROR - File format is not correct\n");
			exit(0);
		}
	}
}

void		ft_updatecoord(t_list *lst, int h, int l, int z)
{
	t_list	*cur;
	int		xgap;
	int		ygap;

	cur = lst;
	if (l != 1)
		xgap = 700 / (l - 1);
	else
		xgap = 700;
	if (h != 1)
		ygap = 700 / (h - 1);
	else
		ygap = 700;
	while (cur != NULL)
	{
		((int *)(cur->content))[0] += 1300 + ((int *)(cur->content))[0] * xgap;
		((int *)(cur->content))[1] += -200 + ((int *)(cur->content))[1] * ygap;
		if (z > 0 && z < 200)
			((int *)(cur->content))[2] *= (200 / z);
		else
			((int *)(cur->content))[2] /= 2;
		cur = cur->next;
	}
}

static int	ft_pointadd(t_list **lst, int x, int y, int z)
{
	int		*coord;
	t_list	*cur;

	if (lst == NULL)
		return (-1);
	coord = (int *)ft_memalloc(3 * sizeof(int));
	if (coord == NULL)
		return (-1);
	coord[0] = x;
	coord[1] = y;
	coord[2] = z;
	if ((cur = ft_lstnew(NULL, 0)) == NULL)
		return (-1);
	cur->content = coord;
	ft_lstadd(lst, cur);
	return (1);
}

int			ft_parse(int fd, t_list **lst, int *size)
{
	char	*str;
	char	**pts;
	int		ok[2];

	size[0] = -1;
	size[2] = 0;
	ok[1] = 0;
	while ((ok[0] = get_next_line(fd, &str)) == 1 && (++(size[0])) != -2)
	{
		size[1] = -1;
		if ((pts = ft_strsplit(str, ' ')) == NULL)
			exit(0);
		ft_checklines(pts, ok);
		while (pts[++(size[1])] != NULL)
		{
			ok[0] = ft_pointadd(lst, size[1], size[0],
					ft_atoi(pts[size[1]]));
			size[2] = ft_max(size[2], ft_abs(ft_atoi(pts[size[1]])));
		}
		ft_strtabdel(pts);
		free(pts);
		free(str);
	}
	++(size[0]);
	return ((ok[0] >= 0) ? 1 : 0);
}
