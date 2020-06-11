/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_param_to_tab.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 14:11:41 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 23:35:59 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

int					my_strlen(char *str)
{
	int	cpt;

	cpt = 0;
	while (*(str + cpt) != '\0')
		cpt++;
	return (cpt);
}

char				*my_strcpy(char *str)
{
	char	*copy;
	int		i;

	copy = (char*)malloc(my_strlen(str) * sizeof(char) + 1);
	if (!copy)
		return (0);
	i = 0;
	while (*(str + i))
	{
		*(copy + i) = *(str + i);
		i++;
	}
	*(copy + i) = '\0';
	return (copy);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par	*s_tab;
	int			i;

	s_tab = (t_stock_par*)malloc(ac * sizeof(t_stock_par) + 1);
	if (!s_tab)
		return (0);
	i = 0;
	while (i < ac)
	{
		(s_tab + i)->size_param = my_strlen(av[i]);
		(s_tab + i)->str = *(av + i);
		(s_tab + i)->copy = my_strcpy(av[i]);
		(s_tab + i)->tab = ft_split_whitespaces(av[i]);
		i++;
	}
	(s_tab + i)->str = NULL;
	return (s_tab);
}
