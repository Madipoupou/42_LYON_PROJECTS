/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_show_tab.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 16:17:27 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/13 00:01:18 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	my_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

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
		digit = (num % div) / (div / 10);
		ft_putchar(digit + 48);
		div /= 10;
	}
}

void	ft_show_tab(struct s_stock_par *par)
{
	int i;
	int j;

	i = 0;
	while ((par + i)->str != 0)
	{	
		my_putstr((par + i)->copy);
		ft_putchar('\n');
		ft_putnbr((par + i)->size_param);
		ft_putchar('\n');
		j = 0;
		while (((par + i)->tab[j]) != 0)
		{
			my_putstr((par + i)->tab[j]);
			ft_putchar('\n');
			j++;
		}
		i++;
	}
}
