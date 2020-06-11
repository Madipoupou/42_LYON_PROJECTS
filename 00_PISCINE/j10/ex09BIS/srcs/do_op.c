/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   do_op.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 01:06:10 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 13:05:10 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/ft.h"

int	main(int argc, char **argv)
{
	int		nb1;
	int		nb2;
	t_opp	type_op;

	if (argc != 4)
		return (0);
	nb1 = ft_atoi(argv[1]);
	nb2 = ft_atoi(argv[3]);
	type_op = ft_select_op(argv[2][0]);
	if (type_op.op_str[0] == '\0')
		type_op.f(0, 0);
	else if (type_op.op_str[0] == '/' && nb2 == 0)
		ft_putstr("Stop : division by zero\n");
	else if (type_op.op_str[0] == '%' && nb2 == 0)
		ft_putstr("Stop : module by zero\n");
	else
	{
		ft_putnbr(type_op.f(nb1, nb2));
		ft_putchar('\n');
	}
	return (0);
}
