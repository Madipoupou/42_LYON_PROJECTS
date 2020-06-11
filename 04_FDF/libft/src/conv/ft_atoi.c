/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 07:22:50 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 15:51:26 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

static void	eval_sign(const char *str, int *i, int *neg)
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

int			ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	eval_sign(str, &i, &neg);
	if (neg == 0 || str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] == '0')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += (str[i] - '0');
		i++;
	}
	return ((int)(res * neg));
}
