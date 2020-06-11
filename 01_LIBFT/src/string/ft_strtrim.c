/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 15:14:06 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 14:00:20 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	j = ft_strlen(s) - 1;
	while (j > i && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
		j--;
	res = ft_strsub(s, i, (j - i + 1));
	if (res == NULL)
		return (NULL);
	return (res);
}
