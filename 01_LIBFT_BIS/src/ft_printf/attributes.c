/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 15:12:23 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 11:14:29 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_evalprec(char *sub)
{
	int	i;

	i = ft_charindexstr('.', sub);
	if (i == -1)
		return (-1);
	return (ft_atoi(sub + i + 1));
}

static int	ft_evalwidth(char *sub)
{
	int	i;
	int	point;
	int	res;

	point = ft_charindexstr('.', sub);
	point = (point == -1 ? (int)ft_strlen(sub) : point);
	i = 1;
	while (i < point)
	{
		res = ft_atoi(sub + i);
		if (res > 0)
			return (res);
		i++;
	}
	return (-1);
}

static int	ft_evalzero(char *sub)
{
	int	i;
	int	point;

	point = ft_charindexstr('.', sub);
	point = (point == -1 ? (int)ft_strlen(sub) : point);
	i = 1;
	while (i < point)
	{
		if (sub[i] == '0')
			return (1);
		if (sub[i] >= '1' && sub[i] <= '9')
			return (0);
		i++;
	}
	return (0);
}

void		ft_init_attributes(t_attributes *ptr)
{
	ptr->h = 0;
	ptr->hh = 0;
	ptr->l = 0;
	ptr->ll = 0;
	ptr->longd = 0;
	ptr->prec = 0;
	ptr->width = 0;
	ptr->opt1 = 0;
	ptr->opt2 = 0;
	ptr->opt3 = 0;
	ptr->opt4 = 0;
	ptr->opt5 = 0;
}

void		ft_eval_attributes(t_attributes *ptr, char *sub)
{
	int	cpt;

	ptr->prec = ft_evalprec(sub);
	ptr->width = ft_evalwidth(sub);
	cpt = ft_cpt_charinstr('h', sub);
	ptr->h = (cpt == 1 ? 1 : 0);
	ptr->hh = (cpt == 2 ? 1 : 0);
	cpt = ft_cpt_charinstr('l', sub);
	ptr->l = (cpt == 1 ? 1 : 0);
	ptr->ll = (cpt == 2 ? 1 : 0);
	ptr->longd = ft_cpt_charinstr('L', sub);
	ptr->opt1 = ft_cpt_charinstr('-', sub);
	ptr->opt2 = ft_cpt_charinstr('+', sub);
	ptr->opt3 = ft_cpt_charinstr('#', sub);
	ptr->opt5 = ft_cpt_charinstr(' ', sub);
	ptr->opt4 = ft_evalzero(sub);
}
