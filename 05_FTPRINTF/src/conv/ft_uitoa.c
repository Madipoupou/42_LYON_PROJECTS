/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_uitoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 21:08:09 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 15:38:42 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

static	size_t	ft_evalsize(unsigned long long int nb)
{
	size_t					i;

	i = 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char			*ft_uitoa(unsigned long long int n)
{
	size_t	len;
	char	*res;
	size_t	i;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_evalsize(n);
	if ((res = ft_strnew(len)) == NULL)
		return (NULL);
	i = 0;
	while (len != 0)
	{
		res[i++] = (char)(n % 10) + '0';
		n /= 10;
		len--;
	}
	ft_strrev(res);
	return (res);
}
