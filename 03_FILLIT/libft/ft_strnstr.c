/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:25:49 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 14:02:39 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	i;
	size_t	mem_i;
	size_t	j;

	if (sub[0] == '\0')
		return ((char *)str);
	i = -1;
	while (str[++i] && i < len && len >= ft_strlen(sub))
	{
		j = 0;
		if (str[i] == sub[j])
		{
			mem_i = i++;
			while (sub[j++] && i < len)
			{
				if (str[i] != sub[j] || (str[i] == '\0' && sub[j] == '\0'))
					break ;
				i++;
			}
			if (j == ft_strlen(sub))
				return ((char *)str + mem_i);
			i = mem_i;
		}
	}
	return (NULL);
}
