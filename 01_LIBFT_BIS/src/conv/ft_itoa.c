/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 15:47:55 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 02:55:33 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static long		ft_evalmul(long long int nbr)
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

static	size_t	ft_evalsize(long long int nb)
{
	size_t			i;
	long long int	mul;

	i = 0;
	if (nb < 0)
		nb *= -1;
	mul = ft_evalmul(nb);
	if (mul < 0)
		return (19);
	while (mul > 0)
	{
		i++;
		mul /= 10;
	}
	return (i);
}

char			*ft_itoa(long long int n)
{
	size_t			size;
	char			*res;
	size_t			i;

	size = ft_evalsize(n);
	if (n + 1 == -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if ((res = ft_strnew((n < 0) ? (size + 1) : size)) == NULL)
		return (NULL);
	if (!(i = 0) && n < 0)
	{
		res[i++] = '-';
		n *= -1;
	}
	while (size != 0)
	{
		res[i++] = (char)(n % 10) + '0';
		n /= 10;
		size--;
	}
	if (res[0] == '-')
		ft_strrev(res + 1);
	else
		ft_strrev(res);
	return (res);
}
