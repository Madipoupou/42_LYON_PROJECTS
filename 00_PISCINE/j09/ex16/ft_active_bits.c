/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_active_bits.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 16:20:53 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/13 16:40:11 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	if (value == 1)
		return (1);
	if (value == 0)
		return (0);
	return (ft_active_bits(value / 2) + (value % 2 == 1));
}
