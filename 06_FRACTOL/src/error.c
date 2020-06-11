/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 19:33:33 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 10:41:51 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_usage(void)
{
	ft_putstr("usage:");
	ft_putendl("\t./fractol [ 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 ]");
	ft_putendl("  - 1: Madelbrot set");
	ft_putendl("  - 2: Mandelbrot two heads");
	ft_putendl("  - 3: Mandelbrot three heads");
	ft_putendl("  - 4: Mandelbrot four heads");
	ft_putendl("  - 5: Julia set");
	ft_putendl("  - 6: Burning ship");
	ft_putendl("  - 7: Weird one");
	ft_putendl("  - 8: Julia three heads");
	ft_putendl("  - 9: Julia four heads");
	return (0);
}

int	ft_puterror(char *str)
{
	ft_putstr(str);
	return (ft_usage());
}
