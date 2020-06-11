/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_find_next_prime.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/07 17:37:35 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/07 20:27:39 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	is_prime(int nb)
{
	long	i;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (0);
	if (nb % 2 == 0)
		return (0);
	i = 3;
	while ((i * i) < nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int		next;

	if (nb < 2)
		return (2);
	if (nb == 2147483647)
		return (0);
	if (nb % 2 == 0)
		next = nb + 1;
	else
		next = nb;
	while (next <= 2147483647)
	{
		if (is_prime(next))
			break ;
		next += 2;
	}
	return (next);
}
