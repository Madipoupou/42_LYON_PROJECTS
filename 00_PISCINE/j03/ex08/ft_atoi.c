/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: exam <marvin@le-101.fr>                    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/06 19:02:01 by exam         #+#   ##    ##    #+#       */
/*   Updated: 2018/07/06 23:34:56 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

long	power(long nb, long pow)
{
	if (pow == 0)
		return (1);
	return (nb * power(nb, (pow - 1)));
}

long	str_size(char *str)
{
	long cpt;

	cpt = 0;
	while (str[cpt] != '\0')
		cpt++;
	return (cpt);
}

long	is_neg(char *str, int i)
{
	if (str[i] == '-')
		return (-1);
	else
		return (1);
}

long	ft_eval_res(char *str, int i, long mul, long res)
{
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res += (str[i] - 48) * mul;
		else
			return (res / (mul * 10));
		i++;
		mul /= 10;
	}
	return (res);
}

int		ft_atoi(char *str)
{
	int		i;
	long	neg;
	long	mul;
	long	res;

	if (str[0] == '\0')
		return (0);
	res = 0;
	mul = power(10, (str_size(str) - 1));
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
		mul /= 10;
	}
	if ((neg = is_neg(str, i)) == -1)
	{
		mul /= 10;
		i++;
	}
	return ((int)(neg * ft_eval_res(str, i, mul, res)));
}
