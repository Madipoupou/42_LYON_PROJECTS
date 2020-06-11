/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_manager.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 18:24:42 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 22:11:29 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_h.h"

char	*ft_cut(char *str, int i, int j)
{
	char	*substr;
	int		k;

	substr = (char*)malloc((j - i + 1) * sizeof(char));
	k = 0;
	while (str[i] != '\0' && i <= j)
	{
		if (str[i] != '(' && str[i] != ')')
		{
			substr[k] = str[i];
			k++;
		}
		i++;
	}
	substr[k] = '\0';
	ft_putstr(substr);
	ft_putchar('\n');
	return (substr);
}

char	*ft_remove(char *str, int i, int j)
{
	char	*str2;
	int		k;

	if (!(str2 = (char*)malloc((ft_strlen(str) + 1) * sizeof(char))))
		return (0);
	k = 0;
	while (str[k] != '\0')
	{
		if (k < i)
			str2[k] = str[k];
		else if (k > j)
			str2[k] = str[k];
		k++;
	}
	str2[k] = '\0';
	return (str2);
}

char	*ft_insert(char *str, char *sub, int i)
{
	char	*res;
	int		k;
	int		j;

	res = (char*)malloc((ft_strlen(str) + ft_strlen(sub) + 1) * sizeof(char));
	if (!res)
		return (0);
	k = -1;
	while (++k < i)
		res[k] = str[k];
	j = 0;
	while (k < (i + ft_strlen(sub)))
	{
		res[k] = sub[j];
		k++;
		j++;
	}
	while (str[k - j] != '\0')
	{
		res[k] = str[k - j];
		k++;
	}
	res[k] = '\0';
	return (res);
}
