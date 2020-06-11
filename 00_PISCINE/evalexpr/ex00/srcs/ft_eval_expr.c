/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_eval_expr.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/22 08:01:33 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 22:26:28 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_h.h"

int	eval_expr(char *str)
{
	int	tot_par;
	int	res;

	str = ft_remove_ws(str);
	tot_par = ft_count_par(str);
	while (tot_par != 0)
	{
		str = ft_extract_par(str, tot_par);
		tot_par = ft_count_par(str);
	}
	res = ft_eval_subexpr(str);
	return (res);
}
