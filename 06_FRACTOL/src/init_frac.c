/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_frac.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 18:19:21 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 14:14:28 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

static void	*ft_thread_func(void *mlx)
{
	int				y;
	t_thread_info	*ptr;

	ptr = (t_thread_info *)mlx;
	y = ptr->y_start;
	while (y < ptr->y_end)
	{
		ptr->ptr_bag->ft_frac(ptr->ptr_bag, ptr->zoomx, ptr->zoomy, y);
		y++;
	}
	free(ptr);
	return (NULL);
}

static void	*ft_cpy_thread_info(t_thread_info *ptr)
{
	t_thread_info	*cpy;

	cpy = (t_thread_info *)malloc(sizeof(t_thread_info));
	if (cpy == NULL)
		return (NULL);
	cpy->ptr_bag = ptr->ptr_bag;
	cpy->zoomx = ptr->zoomx;
	cpy->zoomy = ptr->zoomy;
	cpy->y_start = ptr->y_start;
	cpy->y_end = ptr->y_end;
	return ((void *)cpy);
}

static void	ft_launch_threading(t_thread_info *tmp)
{
	pthread_t	th[NB_THREAD];
	int			i;
	int			gap;

	i = 0;
	gap = (int)FRAC_H / NB_THREAD;
	tmp->y_start = 0;
	tmp->y_end = gap;
	while (tmp->y_end <= FRAC_H)
	{
		pthread_create(&th[i], NULL, &ft_thread_func, ft_cpy_thread_info(tmp));
		tmp->y_start += gap;
		tmp->y_end += gap;
		i++;
	}
	i = 0;
	while (i < NB_THREAD)
	{
		pthread_join(th[i], NULL);
		i++;
	}
}

void		ft_sync_frac(void *ptr)
{
	t_thread_info	tmp;

	tmp.ptr_bag = (t_bag *)ptr;
	tmp.zoomx = FRAC_L / (tmp.ptr_bag->size);
	tmp.zoomy = FRAC_H / (tmp.ptr_bag->size);
	if (tmp.ptr_bag->img_ptr != NULL)
		ft_resetimg(tmp.ptr_bag);
	else
	{
		tmp.ptr_bag->img_ptr = mlx_new_image(tmp.ptr_bag->mlx, FRAC_L, FRAC_H);
		tmp.ptr_bag->img =
			(unsigned int *)mlx_get_data_addr(tmp.ptr_bag->img_ptr,
					tmp.ptr_bag->trash, (tmp.ptr_bag->trash) + 1,
					(tmp.ptr_bag->trash) + 2);
	}
	ft_launch_threading(&tmp);
	mlx_put_image_to_window(tmp.ptr_bag->mlx, tmp.ptr_bag->win,
			tmp.ptr_bag->img_ptr, 400, 50);
}
