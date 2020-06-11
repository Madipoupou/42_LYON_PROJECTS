/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tab.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 01:54:02 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 06:41:06 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/my2.h"

char	**ft_create_colle_tab(void)
{
	char	**tab;
	int		i;

	if (!(tab = (char**)malloc(5 * sizeof(char*))))
		return (0);
	i = 0;
	while (i < SIZE)
	{
		if (!(tab[i] = (char*)malloc(6 * sizeof(char))))
			return (0);
		i++;
	}
	return (tab);
}

void	ft_init_colle_tab1(char **tab)
{
	tab[0][0] = 'o';
	tab[0][1] = 'o';
	tab[0][2] = 'o';
	tab[0][3] = 'o';
	tab[0][4] = '-';
	tab[0][5] = '|';
	tab[1][0] = '/';
	tab[1][1] = '\\';
	tab[1][2] = '\\';
	tab[1][3] = '/';
	tab[1][4] = '*';
	tab[1][5] = '*';
	tab[2][0] = 'A';
	tab[2][1] = 'A';
	tab[2][2] = 'C';
	tab[2][3] = 'C';
	tab[2][4] = 'B';
	tab[2][5] = 'B';
}

void	ft_init_colle_tab2(char **tab)
{
	tab[3][0] = 'A';
	tab[3][1] = 'C';
	tab[3][2] = 'A';
	tab[3][3] = 'C';
	tab[3][4] = 'B';
	tab[3][5] = 'B';
	tab[4][0] = 'A';
	tab[4][1] = 'C';
	tab[4][2] = 'C';
	tab[4][3] = 'A';
	tab[4][4] = 'B';
	tab[4][5] = 'B';
}

void	ft_init_tab(int *possib)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		possib[i] = 1;
		i++;
	}
}

void	ft_clear_table(char **tab)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
