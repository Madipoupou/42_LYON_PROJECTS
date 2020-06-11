/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   context.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 19:32:13 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 14:02:26 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void		ft_draw_rectangle(t_bag *ptr, int x[2], int y[2], int color)
{
	int	i;
	int	j;

	j = y[0];
	while (j <= y[1])
	{
		i = x[0];
		while (i <= x[1])
		{
			mlx_pixel_put(ptr->mlx, ptr->win, i, j, color);
			i++;
		}
		j++;
	}
}

static void	ft_write_header_footer(t_bag *ptr_bag, int color,
		int x[2], int y[2])
{
	x[0] = 0;
	x[1] = 1750;
	y[0] = 0;
	y[1] = 49;
	ft_draw_rectangle(ptr_bag, x, y, color);
	y[0] = 1050;
	y[1] = 1099;
	ft_draw_rectangle(ptr_bag, x, y, color);
	mlx_string_put(ptr_bag->mlx, ptr_bag->win, 800, 15, 0,
			"FRACTOL PROJECT");
	mlx_string_put(ptr_bag->mlx, ptr_bag->win, 1550, 1065, 0,
			"2019 - 101 project");
}

static void	ft_commands2(t_bag *ptr, int color, int x[2], int y[2])
{
	if (ptr->choice == 5 || ptr->choice == 8 || ptr->choice == 9)
	{
		mlx_string_put(ptr->mlx, ptr->win, 1415, 400, color,
				"- Move to edit parameters");
		mlx_string_put(ptr->mlx, ptr->win, 1415, 420, color,
				"- But1: edit parameter 1");
		mlx_string_put(ptr->mlx, ptr->win, 1415, 440, color,
				"- But2: edit parameter 2");
		mlx_string_put(ptr->mlx, ptr->win, 1415, 160, color,
				"- l: lock parameters");
	}
	x[0] = 1545;
	x[1] = 1625;
	y[0] = 80;
	y[1] = 82;
	ft_draw_rectangle(ptr, x, y, color);
	x[0] = 1555;
	x[1] = 1605;
	y[0] = 360;
	y[1] = 362;
	ft_draw_rectangle(ptr, x, y, color);
}

void		ft_commands(t_bag *ptr, int color, int x[2], int y[2])
{
	x[0] = 1405;
	x[1] = 1745;
	y[0] = 53;
	y[1] = 500;
	ft_draw_rectangle(ptr, x, y, 0);
	mlx_string_put(ptr->mlx, ptr->win, 1545, 60, color, "KEYBOARD");
	mlx_string_put(ptr->mlx, ptr->win, 1415, 100, color,
			"- Arrows: move the fractal");
	mlx_string_put(ptr->mlx, ptr->win, 1415, 120, color,
			"- 0: reset current");
	mlx_string_put(ptr->mlx, ptr->win, 1415, 140, color,
			"- +/-: change iterations limit");
	mlx_string_put(ptr->mlx, ptr->win, 1415, 200, color,
			"- m: change color mode");
	mlx_string_put(ptr->mlx, ptr->win, 1415, 220, color,
			"- c: change color");
	mlx_string_put(ptr->mlx, ptr->win, 1415, 240, color,
			"- r: reverse color");
	mlx_string_put(ptr->mlx, ptr->win, 1415, 280, color,
			"- esc: exit");
	mlx_string_put(ptr->mlx, ptr->win, 1555, 340, color, "MOUSE");
	mlx_string_put(ptr->mlx, ptr->win, 1415, 380, color,
			"- Scroll to zoom in or zoom out");
	ft_commands2(ptr, color, x, y);
}

void		ft_context(void *ptr, int color)
{
	t_bag	*ptr_bag;
	int		x[2];
	int		y[2];

	ptr_bag = (t_bag *)ptr;
	x[0] = 0;
	x[1] = 3;
	y[0] = 50;
	y[1] = 1049;
	ft_draw_rectangle(ptr_bag, x, y, color);
	x[0] = 1746;
	x[1] = 1750;
	ft_draw_rectangle(ptr_bag, x, y, color);
	x[0] = 395;
	x[1] = 399;
	ft_draw_rectangle(ptr_bag, x, y, color);
	x[0] = 1400;
	x[1] = 1404;
	ft_draw_rectangle(ptr_bag, x, y, color);
	ft_write_header_footer(ptr_bag, color, x, y);
	ft_commands(ptr_bag, 0xFFFFFF, x, y);
	ft_menu(ptr_bag, x, y, 0xFFFFFF);
	x[0] = 30;
	y[0] = 75;
	ft_menu2(ptr_bag, x, y, 0xFFFFFF);
}
