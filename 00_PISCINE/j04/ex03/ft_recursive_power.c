/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recursive_power.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/07 15:18:03 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/07 15:34:44 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 0 || nb == 1)
		return (nb);
	if (power == 1)
		return (nb);
	if (nb == -1)
	{
		if (power % 2 == 0)
			return (1);
		return (-1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}
