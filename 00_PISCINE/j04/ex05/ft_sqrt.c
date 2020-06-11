/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sqrt.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/07 15:52:15 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/07 16:38:16 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	i;
	long	test;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	i = 2;
	while (1)
	{
		test = i * i;
		if (test == nb)
			return ((int)i);
		else if (test > nb)
			return (0);
		i++;
	}
	return (0);
}
