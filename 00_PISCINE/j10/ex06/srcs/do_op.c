/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   do_op.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/17 01:06:10 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/17 11:42:32 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/ft.h"

int	main(int argc, char **argv)
{
	int	nb1;
	int	nb2;
	int	op;
	int	(*operation[5])(int, int);

	ft_feed_tab(operation);
	if (argc != 4)
		return (0);
	nb1 = ft_atoi(argv[1]);
	nb2 = ft_atoi(argv[3]);
	op = ft_test_op(argv[2]);
	if (op == -1)
		ft_putstr("0\n");
	else if (op == 3 && nb2 == 0)
		ft_putstr("Stop : division by zero\n");
	else if (op == 4 && nb2 == 0)
		ft_putstr("Stop : module by zero\n");
	else
	{
		ft_putnbr(operation[op](nb1, nb2));
		ft_putchar('\n');
	}
	return (0);
}
