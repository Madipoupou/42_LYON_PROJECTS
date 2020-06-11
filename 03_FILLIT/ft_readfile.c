/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reader.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 11:09:11 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/27 16:55:48 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_pushshape(int cpt, t_list **lst, t_list **cur, t_shape **s)
{
	if (cpt != 4)
	{
		ft_memdel((void **)s);
		return (0);
	}
	ft_lstaddend(lst, (*cur = ft_lstnew(NULL, 0)));
	if (*cur == NULL)
		return (0);
	(*cur)->content = *s;
	(*cur)->content_size = sizeof(t_shape *);
	return (1);
}

static int	ft_saveshape(char **sh, t_list **lst, t_list **cur)
{
	static char	c = 'A';
	t_shape		*s;
	int			tab[3];

	if ((s = (t_shape *)ft_memalloc(sizeof(t_shape))) == NULL)
		return (0);
	s->letter = c++;
	tab[0] = 0;
	tab[1] = -1;
	while (++(tab[1]) < SHAPE_SIZE && (tab[2] = -1))
	{
		if (ft_strlen(sh[tab[1]]) != 4 && (tab[0] = 1))
			break ;
		while (++(tab[2]) < 4)
		{
			if (sh[tab[1]][tab[2]] != '.' && sh[tab[1]][tab[2]] != '#')
				return (ft_pushshape(0, NULL, NULL, &s));
			if (sh[tab[1]][tab[2]] == '#' && (tab[0])++ < 4)
			{
				s->coord[tab[0] - 1][0] = tab[1];
				s->coord[tab[0] - 1][1] = tab[2];
			}
		}
	}
	return (ft_pushshape(tab[0], lst, cur, &s));
}

static void	ft_convertcoord(t_list *cur)
{
	int		diff_i;
	int		diff_j;
	size_t	i;
	t_shape	*s;

	if (!cur)
		return ;
	s = (t_shape *)cur->content;
	diff_i = s->coord[0][0];
	diff_j = s->coord[0][1];
	i = 0;
	while (i < SHAPE_SIZE)
	{
		s->coord[i][0] -= diff_i;
		s->coord[i][1] -= diff_j;
		i++;
	}
}

static int	ft_addshape(char **shape, t_list **lst)
{
	t_list	*cur;
	int		ok;

	cur = NULL;
	ok = ft_saveshape(shape, lst, &cur);
	if (ok == 0)
		return (0);
	if (ft_lstlen(*lst) > 26)
		return (0);
	ft_convertcoord(cur);
	ok = ft_checkshape(cur);
	if (ok == 0)
		return (0);
	return (1);
}

int			ft_readfile(int fd, t_list **lst)
{
	char	*str;
	char	*shape[SHAPE_SIZE + 1];
	int		rc;
	int		cpt;

	ft_bzero(shape, (SHAPE_SIZE + 1) * sizeof(char *));
	rc = 1;
	while (rc > 0 && (cpt = 0) == 0)
	{
		while (cpt != SHAPE_SIZE && (rc = get_next_line(fd, &str)) > 0)
			shape[cpt++] = str;
		if (cpt < SHAPE_SIZE && (rc = -1) && ft_strtabdel(shape))
			break ;
		rc = ft_addshape(shape, lst);
		ft_strtabdel(shape);
		if ((cpt < SHAPE_SIZE || rc == 0) && (rc = -1))
			break ;
		rc = get_next_line(fd, &str);
		if (rc < 0)
			rc = -1;
		else if (rc > 0 || (rc > 0 && ft_strequ(str, "") == 0 && (rc = -1)))
			ft_strdel(&str);
	}
	return ((rc == -1) ? 0 : 1);
}
