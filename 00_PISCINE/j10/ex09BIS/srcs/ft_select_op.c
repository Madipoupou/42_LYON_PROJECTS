/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_select_op.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 12:24:41 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 13:03:08 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/ft.h"
#include "./../ft_opp.h"

t_opp	ft_select_op(char c)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if (g_opptab[i].op_str[0] == c)
			return (g_opptab[i]);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		if (g_opptab[i].op_str[0] == '\0')
			return (g_opptab[i]);
		i++;
	}
	return (g_opptab[5]);
}
