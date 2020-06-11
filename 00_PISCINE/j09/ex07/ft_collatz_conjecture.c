/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_collatz_conjecture.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 05:42:04 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/13 10:12:51 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (0);
	if (base % 2 == 0)
		base /= 2;
	else
		base = 3 * base + 1;
	return (1 + ft_collatz_conjecture(base));
}
