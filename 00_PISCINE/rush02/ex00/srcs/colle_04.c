/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   colle_04.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/21 18:43:29 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/21 18:45:19 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/my.h"

void	rush(int x, int y)
{
	int cptl;

	if (x <= 0 || y <= 0)
		return ;
	cptl = 0;
	if (y == 1)
	{
		ft_print_line(x, 'A', 'B', 'C');
		return ;
	}
	while (cptl < y)
	{
		if (cptl == 0)
			ft_print_line(x, 'A', 'B', 'C');
		else if (cptl == (y - 1))
			ft_print_line(x, 'C', 'B', 'A');
		else
			ft_print_line(x, 'B', ' ', 'B');
		++cptl;
	}
}
