/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 13:11:10 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 02:03:45 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/ft.h"

long	eval_div(int nb)
{
	long	div;

	div = 1;
	while (nb / div != 0)
		div *= 10;
	return (div);
}

void	ft_putnbr(int nb)
{
	long	div;
	long	num;
	int		digit;

	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	num = nb;
	if (nb < 0)
	{
		num *= -1;
		ft_putchar('-');
	}
	div = eval_div(nb);
	while (div > 1)
	{
		digit = num / (div / 10);
		ft_putchar(digit + '0');
		div /= 10;
		num %= div;
	}
}
