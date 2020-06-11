/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 01:17:26 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 13:14:58 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void			ft_initjulia(t_bag *ptr_bag)
{
	ptr_bag->edit = -1;
	if (ptr_bag->choice == 5)
	{
		ptr_bag->julia_param[0] = -0.75;
		ptr_bag->julia_param[1] = -0.14;
	}
	else if (ptr_bag->choice == 8)
	{
		ptr_bag->julia_param[0] = 0.400;
		ptr_bag->julia_param[1] = 0.60;
	}
	else if (ptr_bag->choice == 9)
	{
		ptr_bag->julia_param[0] = 0.520;
		ptr_bag->julia_param[1] = 0.60;
	}
	ptr_bag->size = 2.4;
	ptr_bag->posx = 0;
	ptr_bag->posy = 0;
	ptr_bag->i_max = 100;
	ptr_bag->lim = 4;
	ptr_bag->zoom = 1;
}

static double	ft_julia_re(t_bag *ptr, double z[2], double c)
{
	if (ptr->choice == 5)
		return (z[0] * z[0] - z[1] * z[1] + c);
	else if (ptr->choice == 8)
		return (z[0] * z[0] * z[0] - 3 * z[0] * z[1] * z[1] + c);
	else if (ptr->choice == 9)
	{
		return (z[0] * z[0] * z[0] * z[0] + z[1] * z[1] * z[1] * z[1] -
				6 * z[0] * z[0] * z[1] * z[1] + c);
	}
	return (0);
}

static double	ft_julia_im(t_bag *ptr, double z1, double temp, double c)
{
	if (ptr->choice == 5)
		return (2 * z1 * temp + c);
	else if (ptr->choice == 8)
		return (-1 * z1 * z1 * z1 + 3 * temp * temp * z1 + c);
	else if (ptr->choice == 9)
		return (4 * temp * temp * temp * z1 - 4 * temp * z1 * z1 * z1 + c);
	return (0);
}

void			ft_julia(t_bag *ptr, double zoomx, double zoomy, int y)
{
	int		x;
	double	z[2];
	double	temp;
	int		temp2;
	int		i[2];

	i[1] = y * FRAC_L;
	x = -1;
	while (++x < FRAC_L && (i[0] = -1))
	{
		z[0] = x / zoomx + ptr->posx - ptr->size / 2;
		z[1] = y / zoomy + ptr->posy - ptr->size / 2;
		while (++i[0] < ptr->i_max && (z[0] * z[0] + z[1] * z[1] < 4))
		{
			temp = z[0];
			z[0] = ft_julia_re(ptr, z, ptr->julia_param[0]);
			z[1] = ft_julia_im(ptr, z[1], temp, ptr->julia_param[1]);
		}
		temp2 = (100 * i[0] / ptr->i_max) / 10;
		ptr->img[i[1]++] = (ptr->col.mode == 1 ?
			ptr->col.color[temp2] :
			(int)((double)i[0] / ptr->i_max * ptr->col.random));
	}
}
