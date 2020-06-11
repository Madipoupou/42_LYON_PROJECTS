/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   keyboard_manager.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/31 02:00:52 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 15:34:04 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

static int	ft_move(t_bag *ptr, int key)
{
	if (key == 126)
		ptr->posy += ptr->move_value;
	else if (key == 125)
		ptr->posy -= ptr->move_value;
	else if (key == 123)
		ptr->posx += ptr->move_value;
	else
		ptr->posx -= ptr->move_value;
	return (0);
}

static int	ft_editparam(t_bag *ptr_bag, int key)
{
	if (key == 69)
		ptr_bag->i_max += 10;
	else if (key == 78 && ptr_bag->i_max > 10)
		ptr_bag->i_max -= 10;
	ft_info_iter(ptr_bag);
	return (0);
}

static void	ft_close_prog(t_bag *ptr_bag)
{
	mlx_destroy_image(ptr_bag->mlx, ptr_bag->img_ptr);
	mlx_destroy_image(ptr_bag->mlx, ptr_bag->win);
	exit(0);
}

static void	ft_color_random(t_bag *ptr_bag)
{
	ptr_bag->col.mode = (ptr_bag->col.mode == 1 ? 2 : 1);
	if (ptr_bag->col.mode == 2)
		ft_info_color_random(ptr_bag);
	else
		ft_info_color(ptr_bag);
}

int			ft_keymg(int key, void *ptr)
{
	t_bag	*ptr_bag;

	ptr_bag = (t_bag *)ptr;
	if (key == 69 || key == 78)
		ft_editparam(ptr_bag, key);
	else if (key >= 123 && key <= 126)
		ft_move(ptr_bag, key);
	else if (key == 15 && ptr_bag->col.mode == 1)
		ft_colormg_reverse(ptr_bag);
	else if (key == 8)
		ft_colormg(ptr_bag);
	else if (key == 46)
		ft_color_random(ptr_bag);
	else if (key == 82)
	{
		ft_reinit(ptr_bag, ptr_bag->choice);
		ft_initcol(ptr_bag);
	}
	else if (key == 37)
		ptr_bag->edit = 0;
	else if (key == 53)
		ft_close_prog(ptr_bag);
	ft_sync_frac(ptr);
	return (0);
}
