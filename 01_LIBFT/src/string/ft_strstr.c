/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 16:35:23 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 14:02:44 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

char	*ft_strstr(const char *str, const char *sub)
{
	size_t	i;
	size_t	mem_i;
	size_t	j;

	if (sub[0] == '\0')
		return ((char *)str);
	i = -1;
	while (str[++i])
	{
		j = 0;
		if (str[i] == sub[j])
		{
			mem_i = i++;
			while (sub[j++])
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
