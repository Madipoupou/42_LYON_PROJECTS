/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sortstrtab.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 15:39:12 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 16:31:10 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

static void		ft_swap(char **tab, size_t i, size_t j)
{
	char	*temp;

	temp = tab[i];
	tab[i] = tab[j];
	tab[j] = temp;
}

static size_t	ft_strtablen(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

void			ft_sortstrtab(char **tab)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (tab != NULL)
	{
		i = 0;
		len = ft_strtablen(tab);
		if (len <= 1)
			return ;
		while (i < len - 1)
		{
			j = i + 1;
			while (j < len)
			{
				if (ft_strcmp(tab[i], tab[j]) > 0)
					ft_swap(tab, i, j);
				j++;
			}
			i++;
		}
	}
}
