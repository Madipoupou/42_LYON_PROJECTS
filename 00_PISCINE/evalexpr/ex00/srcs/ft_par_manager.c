/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_par_manager.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 10:35:54 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 23:16:05 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_h.h"

int		ft_count_par(char *str)
{
	int cpt;
	int i;

	cpt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
			cpt++;
		i++;
	}
	return (cpt);
}

char	*ft_extract_par(char *str, int tot_par)
{
	int		i;
	int		j;
	char	*substr;
	int		par_num;

	i = 0;
	par_num = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
			par_num++;
		if (par_num == tot_par)
			break ;
		i++;
	}
	j = i;
	while (str[j] != ')')
		j++;
	substr = ft_cut(str, i, j);
	str = ft_remove(str, i, j);
	substr = ft_itoa(ft_eval_subexpr(substr));
	str = ft_insert(str, substr, i);
	ft_putstr(str);
	return (str);
}
