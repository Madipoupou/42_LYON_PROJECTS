/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_push_params.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 20:01:17 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 20:44:14 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_list.h"

long	power(int num, int pow)
{
	int		i;
	long	res;

	i = 0;
	res = 1;
	while (i < pow)
	{
		res *= num;
		i++;
	}
	return (res);
}

int		str_len(char *str)
{
	int cpt;

	cpt = 0;
	while (str[cpt] != '\0')
		cpt++;
	return (cpt);
}

void	first_test(char *str, int *i, int *signe)
{
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		*i = *i + 1;
	if (str[*i] == '-')
		{
			*i = *i + 1;
		*signe = -1;
	}
	else if (str[*i] == '+')
		*i = *i + 1;
	if (str[*i] < '0' || str[*i] > '9')
		*i = -1;
}

int		ft_atoi(char *str)
{
	int		i;
	int		signe;
	long	res;
	long	mul;

	res = 0;
	i = 0;
	signe = 1;
	first_test(str, &i, &signe);
	if (i == -1)
		return (0);
	mul = power(10, (str_len(str) - i));
	while (i < str_len(str))
	{
		if (str[i] >= '0' && str[i] <= '9')
			res += (str[i] - 48) * (mul / 10);
		else
			break ;
		i++;
		mul /= 10;
	}
	return ((int)((signe * res) / (mul)));
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*my_list;
	int		i;

	my_list = 0;
	if (ac <= 0)
		return (0);
	i = 1;
	while (i < ac)
	{
		ft_list_push_front(&my_list, ft_atoi(av[i]));
		i++;
	}
	return (my_list);
}
