/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 07:22:50 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 18:28:18 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

static long long int	eval_mul(const char *str, int i)
{
	long long int	mul;

	mul = 1;
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		mul *= 10;
		i++;
	}
	return (mul);
}

static void				eval_sign(const char *str, int *i, int *neg)
{
	if (str[*i] == '-')
	{
		*neg = -1;
		*i = *i + 1;
	}
	else if (str[*i] == '+')
	{
		*neg = 1;
		*i = *i + 1;
	}
	else if (str[*i] >= '0' && str[*i] <= '9')
		*neg = 1;
	else
		*neg = 0;
}

static int				ft_testlong(long long int res, int neg)
{
	if (neg == -1)
	{
		if (res == 9223372036854775807)
			return (1);
		else
			return (0);
	}
	return (-1);
}

static size_t			ft_strlenatoi(const char *str)
{
	size_t	cpt;

	cpt = 0;
	while (str[cpt] != '\0' && ft_isdigit(str[cpt]))
	{
		cpt++;
	}
	return (cpt);
}

int						ft_atoi(const char *str)
{
	int				i;
	int				neg;
	long long int	mul;
	long long int	res;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	eval_sign(str, &i, &neg);
	if (neg == 0 || str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] == '0')
		i++;
	if (ft_strlenatoi(str + i) > 19)
		return (ft_testlong(0, neg));
	mul = eval_mul(str, i);
	res = 0;
	while (mul >= 1 && (size_t)i < ft_strlen(str))
	{
		res += (str[i++] - '0') * mul;
		mul /= 10;
	}
	if (res < 0 || res == 9223372036854775807)
		return (ft_testlong(res, neg));
	return ((int)(res * neg));
}
