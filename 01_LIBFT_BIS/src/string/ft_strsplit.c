/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:25:12 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 14:09:22 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwd(char const *s, char c)
{
	size_t	i;
	size_t	cpt;
	size_t	in_wd;

	i = 0;
	cpt = 0;
	in_wd = 0;
	while (s[i])
	{
		if (s[i] != c && in_wd == 0)
		{
			in_wd = 1;
			cpt++;
		}
		else if (in_wd == 1 && s[i] == c)
			in_wd = 0;
		i++;
	}
	return (cpt);
}

static	size_t	ft_evallen(char const *s, char c, size_t pos)
{
	size_t	len;

	len = 0;
	while (s[pos] && s[pos] != c)
	{
		len++;
		pos++;
	}
	return (len);
}

static char		*ft_extract_char(char const *s, char c, size_t *pos)
{
	size_t	i;
	size_t	len;
	char	*res;

	while (s[*pos] && s[*pos] == c)
		*pos = *pos + 1;
	len = ft_evallen(s, c, *pos);
	res = ft_strnew(len);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[*pos];
		i++;
		*pos = *pos + 1;
	}
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	char	*temp;
	size_t	tot;
	size_t	wd_i;
	size_t	pos;

	if (s != NULL)
	{
		tot = ft_countwd(s, c);
		if ((res = (char **)ft_memalloc((tot + 1) * sizeof(char*))) == NULL)
			return (NULL);
		wd_i = 0;
		pos = 0;
		while (wd_i < tot)
		{
			temp = ft_extract_char(s, c, &pos);
			res[wd_i] = temp;
			wd_i++;
		}
		return (res);
	}
	return (NULL);
}
