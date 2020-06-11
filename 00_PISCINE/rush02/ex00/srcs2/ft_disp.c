/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_disp.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 00:36:18 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 02:02:24 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/my2.h"

void	ft_disp(int colle, int num_line, int line_len)
{
	ft_putstr("[colle-0");
	ft_putnbr(colle);
	ft_putstr("] [");
	ft_putnbr(line_len);
	ft_putstr("] [");
	ft_putnbr(num_line);
	ft_putstr("]");
}

void	ft_error(void)
{
	ft_putstr("aucune");
}
