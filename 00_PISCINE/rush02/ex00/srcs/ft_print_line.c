/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/21 18:25:53 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/21 21:03:18 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/my.h"

void	ft_print_line(int a, char c1, char c2, char c3)
{
	int cptc;

	cptc = 0;
	if (a == 1)
	{
		ft_putchar(c1);
		ft_putchar('\n');
		return ;
	}
	ft_putchar(c1);
	while (cptc++ < (a - 2))
		ft_putchar(c2);
	ft_putchar(c3);
	ft_putchar('\n');
}
