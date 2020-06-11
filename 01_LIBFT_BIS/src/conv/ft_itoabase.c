/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoabase.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:40:49 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 15:37:31 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_convert(long long int n, int base, char *ref, char *res)
{
	if (n / base == 0)
	{
		res[ft_strlen(res)] = ref[n % base];
		return ;
	}
	ft_convert((n / base), base, ref, res);
	res[ft_strlen(res)] = ref[n % base];
}

char		*ft_itoabase(long long int n, int base)
{
	char	*res;
	char	*temp;
	char	*ref;

	if (base == 10)
		return (ft_itoa(n));
	ref = ft_strdup("0123456789abcdefghijklmnopqrstuvwxyz");
	if (ref == NULL)
		return (NULL);
	if (base < 2 || base > 30 || n < 0)
		return (NULL);
	res = ft_strnew(65);
	if (res == NULL)
		return (NULL);
	ft_convert(n, base, ref, res);
	temp = res;
	res = ft_strdup(res);
	free(temp);
	return (res);
}
