/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_test_op.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 01:25:35 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 11:24:28 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/ft.h"

int	ft_test_op(char *str)
{
	if (str[0] == '+')
		return (0);
	else if (str[0] == '-')
		return (1);
	else if (str[0] == '*')
		return (2);
	else if (str[0] == '/')
		return (3);
	else if (str[0] == '%')
		return (4);
	return (-1);
}
