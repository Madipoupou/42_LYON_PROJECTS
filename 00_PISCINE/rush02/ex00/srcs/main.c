/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-mour <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/08 13:39:24 by jde-mour     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/21 20:27:41 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/my.h"

int	main(int argc, char **argv)
{
	int		a;
	int		b;

	if (argc != 3)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[2]);
	if (argc == 3)
		rush(a, b);
	else if (a <= 0 || b <= 0)
		return (0);
	return (0);
}
