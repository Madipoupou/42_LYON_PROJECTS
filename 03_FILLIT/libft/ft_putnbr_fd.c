/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:07:09 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 11:07:27 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

static long	eval_mul(long num)
{
	long	mul;

	mul = 1;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		mul *= 10;
		num /= 10;
	}
	return (mul / 10);
}

void		ft_putnbr_fd(int n, int fd)
{
	long	num;
	long	mul;

	num = (long)n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	mul = eval_mul(num);
	while (mul != 0)
	{
		ft_putchar_fd((int)(num / mul) + '0', fd);
		num %= mul;
		mul /= 10;
	}
}
