/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_eval_subexpr.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 18:53:29 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 22:55:13 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_h.h"

char	*ft_replace_after_op(char *str, char *res, int i, int j)
{
	int		k;
	char	*new;

	new = (char*)malloc((ft_strlen(str) + ft_strlen(res) + 1) * sizeof(char));
	if (!new)
		return (0);
	k = -1;
	while (++k < j)
		new[k] = str[k];
	while ((k - j) < ft_strlen(res))
	{
		new[k] = res[k - j];
		k++;
	}
	while (str[i] != '\0')
	{
		new[k] = str[i];
		k++;
		i++;
	}
	new[k] = '\0';
	return (new);
}

char	*ft_prior_op(char *str, int i)
{
	char	*res;
	char	op;
	int		j;
	int		a;
	int		b;

	op = str[i];
	j = i - 1;
	i++;
	b = ft_atoi(str + i);
	while (str[i] != '\0' && !ft_is_operator(str[i]))
		i++;
	while (j >= 0 && !ft_is_operator(str[j]))
		j--;
	if (j != 0)
		j++;
	a = ft_atoi(str + j);
	res = ft_itoa(ft_doop(op, a, b));
	str = ft_replace_after_op(str, res, i, j);
	return (str);
}

char	*ft_minor_op(char *str)
{
	char	*res;
	char	op;
	int		i;
	int		j;
	int		b;

	i = 0;
	while (!ft_is_operator(str[i]))
		i++;
	op = str[i];
	j = i - 1;
	i++;
	b = ft_atoi(str + i);
	while (str[i] != '\0' && !ft_is_operator(str[i]))
		i++;
	while (j >= 0 && !ft_is_operator(str[j]))
		j--;
	if (j != 0)
		j++;
	res = ft_itoa(ft_doop(op, ft_atoi(str + j), b));
	str = ft_replace_after_op(str, res, i, j);
	return (str);
}

int		ft_eval_subexpr(char *str)
{
	int i;

	while (ft_count_op(str))
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] == '*' || str[i] == '/' || str[i] == '%')
				break ;
			i++;
		}
		if (i != ft_strlen(str))
			str = ft_prior_op(str, i);
		else
			str = ft_minor_op(str);
	}
	return (ft_atoi(str));
}
