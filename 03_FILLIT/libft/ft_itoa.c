/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 15:47:55 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 18:28:28 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

static long		ft_evalmul(long nbr)
{
	long	mul;

	mul = 1;
	if (nbr == 0)
		return (mul);
	while (nbr != 0)
	{
		mul *= 10;
		nbr /= 10;
	}
	return (mul / 10);
}

static	size_t	ft_evalsize(long nb)
{
	size_t	i;
	long	mul;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	mul = ft_evalmul(nb);
	while (mul > 0)
	{
		i++;
		mul /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	long	nbr;
	long	mul;
	char	*res;
	size_t	i;

	nbr = (long)n;
	if ((res = ft_strnew(ft_evalsize(nbr))) == NULL)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		res[i++] = '-';
		nbr *= -1;
	}
	mul = ft_evalmul(nbr);
	while (mul != 0)
	{
		res[i++] = (nbr / mul) + '0';
		nbr %= mul;
		mul /= 10;
	}
	return (res);
}
