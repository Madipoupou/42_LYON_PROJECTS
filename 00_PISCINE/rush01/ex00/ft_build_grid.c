/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_build_grid.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/15 00:17:40 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/15 16:26:09 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_sudoku.h"

int	**ft_build_grid(char **argv)
{
	int	i;
	int	j;
	int	**tab;

	if (!(tab = (int**)malloc(SIZE * sizeof(int*))))
		return (NULL);
	i = 0;
	while (i < SIZE)
	{
		if (!(tab[i] = (int*)malloc(SIZE * sizeof(int))))
			return (NULL);
		j = 0;
		while (j < SIZE)
		{
			if (argv[i + 1][j] >= '0' && argv[i + 1][j] <= '9')
				tab[i][j] = argv[i + 1][j] - '0';
			else if (argv[i + 1][j] == '.')
				tab[i][j] = 0;
			else
				return (NULL);
			j++;
		}
		i++;
	}
	return (tab);
}
