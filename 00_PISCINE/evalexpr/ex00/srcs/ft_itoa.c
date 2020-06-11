/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 17:55:42 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 23:12:10 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_h.h"

void	ft_eval(int nb, int *len, int *mul, int *neg)
{
	int nb2;

	*len = 0;
	*mul = 1;
	if (nb < 0)
	{
		*neg = -1;
		nb = nb * -1;
	}
	nb2 = nb;
	while (nb2 > 0 || *len == 0)
	{
		nb2 = nb2 / 10;
		*len = *len + 1;
		*mul *= 10;
	}
}

char	*ft_itoa(int nb)
{
	int		len;
	int		mul;
	int		neg;
	int		nb2;
	char	*str;

	ft_eval(nb, &len, &mul, &neg);
	if (!(str = (char*)malloc((len + 2) * sizeof(char))))
		return (0);
	nb2 = -1;
	if (neg == -1)
	{
		nb = -1 * nb;
		str[0] = '-';
		len++;
		nb2++;
	}
	while (++nb2 < len)
	{
		mul /= 10;
		str[nb2] = (nb / mul) + '0';
		nb = nb % mul;
	}
	str[nb2] = '\0';
	return (str);
}
