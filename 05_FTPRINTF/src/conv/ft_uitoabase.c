/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ullitoabase.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 17:27:27 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 15:39:13 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

static void	ft_convert(unsigned long long int n, int base, char *ref, char *res)
{
	if (n / base == 0)
	{
		res[ft_strlen(res)] = ref[n % base];
		return ;
	}
	ft_convert((n / base), base, ref, res);
	res[ft_strlen(res)] = ref[n % base];
}

char		*ft_uitoabase(unsigned long long int n, int base)
{
	char	*res;
	char	*temp;
	char	*ref;

	if (base == 10)
		return (ft_itoa(n));
	ref = ft_strdup("0123456789abcdefghijklmnopqrstuvwxyz");
	if (ref == NULL)
		return (NULL);
	if (base < 2 || base > 30)
		return (NULL);
	res = ft_strnew(65);
	if (res == NULL)
		return (NULL);
	ft_convert(n, base, ref, res);
	temp = res;
	res = ft_strdup(res);
	free(ref);
	free(temp);
	return (res);
}
