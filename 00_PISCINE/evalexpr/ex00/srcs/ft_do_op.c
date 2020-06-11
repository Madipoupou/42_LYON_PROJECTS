/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_do_op.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 20:56:43 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 20:59:14 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_h.h"

int	ft_doop(char c, int a, int b)
{
	if (c == '+')
		return (ft_add(a, b));
	if (c == '-')
		return (ft_sub(a, b));
	if (c == '*')
		return (ft_mul(a, b));
	if (c == '/')
		return (ft_div(a, b));
	if (c == '%')
		return (ft_mod(a, b));
	return (0);
}
