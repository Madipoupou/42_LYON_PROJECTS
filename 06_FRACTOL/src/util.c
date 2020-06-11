/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/25 16:58:11 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/31 11:38:07 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void	ft_resetimg(t_bag *ptr)
{
	int	i;

	i = 0;
	while (i < (FRAC_L * FRAC_H))
		(ptr->img)[i++] = 0;
	return ;
}

double	ft_abs(double f)
{
	return (f >= 0. ? f : -f);
}
