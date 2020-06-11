/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_iterative_power.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/07 14:21:06 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/07 15:08:58 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	long	res;
	int		i;

	if (power < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	if (nb == -1)
	{
		if (power % 2 == 0)
			return (1);
		return (-1);
	}
	i = 0;
	res = 1;
	while (i < power)
	{
		res *= nb;
		if (res > 2147483647)
			return (0);
		i++;
	}
	return ((int)res);
}
