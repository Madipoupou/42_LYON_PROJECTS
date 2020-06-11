/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   colle_2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/21 16:55:43 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/22 16:55:59 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/my2.h"

int	main(void)
{
	t_list	*begin;
	int		num_line;
	int		tot_char;
	int		possib[SIZE];

	begin = NULL;
	ft_init_tab(possib);
	tot_char = 0;
	num_line = ft_fill_list(&begin, &tot_char);
	if (num_line <= 0)
	{
		ft_putstr("aucune\n");
		return (0);
	}
	ft_parse(possib, num_line, tot_char, begin);
	ft_clean_list(begin);
	ft_result(possib, num_line, (tot_char / num_line));
	return (0);
}
