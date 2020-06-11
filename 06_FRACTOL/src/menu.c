/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   menu.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 10:47:59 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 14:18:27 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void		ft_menu2(t_bag *ptr, int x[2], int y[2], int color)
{
	mlx_string_put(ptr->mlx, ptr->win, x[0], y[0], color, "Mandelbrot");
	y[0] += 70;
	mlx_string_put(ptr->mlx, ptr->win, x[0], y[0], color,
			"Mandelbrot two heads");
	y[0] += 70;
	mlx_string_put(ptr->mlx, ptr->win, x[0], y[0], color,
			"Mandelbrot three heads");
	y[0] += 70;
	mlx_string_put(ptr->mlx, ptr->win, x[0], y[0], color,
			"Mandelbrot four heads");
	y[0] += 70;
	mlx_string_put(ptr->mlx, ptr->win, x[0], y[0], color,
			"Julia");
	y[0] += 70;
	mlx_string_put(ptr->mlx, ptr->win, x[0], y[0], color,
			"Burning ship");
	y[0] += 70;
	mlx_string_put(ptr->mlx, ptr->win, x[0], y[0], color,
			"Weird one");
	y[0] += 70;
	mlx_string_put(ptr->mlx, ptr->win, x[0], y[0], color,
			"Julia three heads");
	y[0] += 70;
	mlx_string_put(ptr->mlx, ptr->win, x[0], y[0], color,
			"Julia four heads");
}

void		ft_reinit(t_bag *ptr_bag, int choice)
{
	int	x[2];
	int	y[2];

	ptr_bag->choice = choice;
	if ((choice >= 1 && choice <= 4) || choice == 6 || choice == 7)
	{
		ptr_bag->ft_init = &ft_initmand;
		ptr_bag->ft_frac = &ft_mandelbrot;
	}
	else if (choice == 5 || (choice >= 8 && choice <= 9))
	{
		ptr_bag->ft_init = &ft_initjulia;
		ptr_bag->ft_frac = &ft_julia;
	}
	ptr_bag->move_value = 0.10;
	(ptr_bag->ft_init)(ptr_bag);
	ft_info_panel(ptr_bag);
	ft_sync_frac(ptr_bag);
	ft_commands(ptr_bag, 0xFFFFFF, x, y);
}

void		ft_menu_selector(t_bag *ptr_bag, int y)
{
	if (y < 120)
		ft_reinit(ptr_bag, 1);
	else if (y < 190)
		ft_reinit(ptr_bag, 2);
	else if (y < 260)
		ft_reinit(ptr_bag, 3);
	else if (y < 330)
		ft_reinit(ptr_bag, 4);
	else if (y < 400)
		ft_reinit(ptr_bag, 5);
	else if (y < 470)
		ft_reinit(ptr_bag, 6);
	else if (y < 540)
		ft_reinit(ptr_bag, 7);
	else if (y < 610)
		ft_reinit(ptr_bag, 8);
	else if (y < 680)
		ft_reinit(ptr_bag, 9);
}

void		ft_menu(t_bag *ptr_bag, int x[2], int y[2], int color)
{
	int	i;

	i = 0;
	x[0] = 4;
	x[1] = 394;
	y[0] = 50;
	y[1] = 54;
	while (i < 10)
	{
		ft_draw_rectangle(ptr_bag, x, y, color);
		y[0] += 70;
		y[1] += 70;
		i++;
	}
	x[0] = 4;
	x[1] = 8;
	y[0] = 50;
	y[1] -= 70;
	ft_draw_rectangle(ptr_bag, x, y, color);
	x[0] = 390;
	x[1] = 394;
	ft_draw_rectangle(ptr_bag, x, y, color);
}
