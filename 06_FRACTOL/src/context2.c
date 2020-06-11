/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   context2.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 13:32:32 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 15:27:42 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void	ft_info_color2(t_bag *ptr_bag, int x[2], int y[2])
{
	x[0] = 1537;
	x[1] = 1556;
	ft_draw_rectangle(ptr_bag, x, y, ptr_bag->col.color[4]);
	x[0] = 1557;
	x[1] = 1576;
	ft_draw_rectangle(ptr_bag, x, y, ptr_bag->col.color[4]);
	x[0] = 1577;
	x[1] = 1596;
	ft_draw_rectangle(ptr_bag, x, y, ptr_bag->col.color[5]);
	x[0] = 1597;
	x[1] = 1616;
	ft_draw_rectangle(ptr_bag, x, y, ptr_bag->col.color[6]);
	x[0] = 1617;
	x[1] = 1636;
	ft_draw_rectangle(ptr_bag, x, y, ptr_bag->col.color[7]);
	x[0] = 1637;
	x[1] = 1656;
	ft_draw_rectangle(ptr_bag, x, y, ptr_bag->col.color[8]);
	x[0] = 1657;
	x[1] = 1676;
	ft_draw_rectangle(ptr_bag, x, y, ptr_bag->col.color[9]);
	x[0] = 1677;
	x[1] = 1697;
	ft_draw_rectangle(ptr_bag, x, y, ptr_bag->col.color[10]);
}

void	ft_info_color(t_bag *ptr_bag)
{
	int	x[2];
	int	y[2];

	x[0] = 1449;
	x[1] = 1600;
	y[0] = 595;
	y[1] = 675;
	ft_draw_rectangle(ptr_bag, x, y, 0);
	mlx_string_put(ptr_bag->mlx, ptr_bag->win, 1450, 595, 0xFFFFFF,
			"- color:");
	x[0] = 1457;
	x[1] = 1476;
	y[0] = 630;
	y[1] = 660;
	ft_draw_rectangle(ptr_bag, x, y, ptr_bag->col.color[0]);
	x[0] = 1477;
	x[1] = 1496;
	ft_draw_rectangle(ptr_bag, x, y, ptr_bag->col.color[1]);
	x[0] = 1497;
	x[1] = 1516;
	ft_draw_rectangle(ptr_bag, x, y, ptr_bag->col.color[2]);
	x[0] = 1517;
	x[1] = 1536;
	ft_draw_rectangle(ptr_bag, x, y, ptr_bag->col.color[3]);
	ft_info_color2(ptr_bag, x, y);
}

void	ft_info_color_random(t_bag *ptr_bag)
{
	int	x[2];
	int	y[2];

	x[0] = 1449;
	x[1] = 1700;
	y[0] = 595;
	y[1] = 675;
	ft_draw_rectangle(ptr_bag, x, y, 0);
	mlx_string_put(ptr_bag->mlx, ptr_bag->win, 1450, 595, 0xFFFFFF,
			"- color:");
	mlx_string_put(ptr_bag->mlx, ptr_bag->win, 1500, 630, 0xFFFFFF,
			"RANDOM");
}

void	ft_info_iter(t_bag *ptr_bag)
{
	char	*str;
	int		x[2];
	int		y[2];

	x[0] = 1449;
	x[1] = 1600;
	y[0] = 565;
	y[1] = 595;
	ft_draw_rectangle(ptr_bag, x, y, 0);
	str = ft_itoa(ptr_bag->i_max);
	if (str == NULL)
		return ;
	mlx_string_put(ptr_bag->mlx, ptr_bag->win, 1450, 565, 0xFFFFFF,
			"- max iter:");
	mlx_string_put(ptr_bag->mlx, ptr_bag->win, 1565, 565, 0xFFFFFF,
			str);
	free(str);
}

void	ft_info_panel(t_bag *ptr_bag)
{
	int	x[2];
	int	y[2];

	x[0] = 1425;
	x[1] = 1730;
	y[0] = 530;
	y[1] = 680;
	ft_draw_rectangle(ptr_bag, x, y, 0xFFFFFF);
	x[0] = 1428;
	x[1] = 1727;
	y[0] = 533;
	y[1] = 677;
	ft_draw_rectangle(ptr_bag, x, y, 0);
	mlx_string_put(ptr_bag->mlx, ptr_bag->win, 1430, 535, 0xFFFFFF,
			"INFOS:");
	x[0] = 1430;
	x[1] = 1485;
	y[0] = 555;
	y[1] = 557;
	ft_draw_rectangle(ptr_bag, x, y, 0xFFFFFF);
	ft_info_iter(ptr_bag);
	ft_info_color(ptr_bag);
}
