/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_possib.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 01:32:00 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 02:03:30 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/my2.h"

void	ft_result(int *possib, int line_num, int line_len)
{
	int cpt;
	int i;
	int j;

	i = -1;
	cpt = 0;
	while (++i < 5)
		if (possib[i] == 1)
			cpt++;
	if (cpt == 0)
		ft_error();
	i = 0;
	j = 0;
	while (++i && j < cpt)
		if (possib[i - 1] == 1)
		{
			ft_disp((i - 1), line_num, line_len);
			if (j < cpt - 1)
				ft_putstr(" || ");
			j++;
		}
	ft_putchar('\n');
}
