/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:14:52 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 13:57:44 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (s != NULL)
	{
		res = ft_strnew(ft_strlen(s));
		if (res == NULL)
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			res[i] = (*f)(i, s[i]);
			i++;
		}
		return (res);
	}
	return (NULL);
}
